#include <fstream>
#include <iomanip>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
using namespace std;

double L = 1;

double v = 1/(10*10*10*10);

double dx = 1/(10*10);

double dt = 0.25*(dx*dx)/v;

int n = int(L/dx);

double Tpas[n][n];
double T[n][n];
ofstream outfile;


//El entero k es 1 para condicion de fronteras abiertas, 2 para periodicas y 3 para fijas, y n es el numero de iteraciones de la funcion
void solucionDifusion(int);

int main()
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            xActual=(i/n)*L;
            yActual=(j/n)*L;
            
            if(xActual>0.20 && xActual<0.40 && yActual>0.50 && yActual<0.70)
            {
                T[i][j] = 100;
            }
            
            else
            {
                T[i][j] = 50;
            }
        }
    }
    
    solucionDifusion(1);
    solucionDifusion(2);
    solucionDifusion(3);
}

void solucionDifusion(int k)
{
    double tiempo = 0.0;
    int t1 = 0;
    int t2 = int(100/dt);
    int t3 = int(2500/dt);
    
    double r = 0.5*v*dt/(dx*dx);
    
    //Fronteras abiertas
    if(k == 1)
    {
        outfile.open("datosFrontera1.dat");
        
        for(int t = 0; t<max; t++)
        {
            if(t == t1 || t == t2 || t == t3)
            {
                for(int x = 0; x<n; x++)
                {
                    for(int y = 0; y<n; y++)
                    {
                        outfile<<T[x][y]<<" ";
                    }
                    
                    outfile<<endl;
                }
            }
            
            for(int i = 0; i<n; i++)
            {
                for(int j = 0; j<n; j++)
                {
                    
                    if(i == 0 || i == n || j == 0 || j == n)
                    {
                        if(j != 0 || j != n || i == 0)
                        {
                            T[i][j] +=  r*(Tpas[0][j] + Tpas[1][j] - 4*Tpas[0][j] + Tpas[0][j-1] + Tpas[0][j+1]);
                        }
                        
                        else if(j != 0 || j != n || i == n)
                        {
                            T[i][j] +=  r*(Tpas[n-1][j] + Tpas[n][j] - 4*Tpas[n][j] + Tpas[n][j-1] + Tpas[n][j+1]);
                        }
                        
                        else if(i != 0 || i != n || j == 0)
                        {
                            T[i][j] +=  r*(Tpas[i-1][0] + Tpas[i+1][0] - 4*Tpas[i][0] + Tpas[i][0] + Tpas[i][1]);
                        }
                        
                        else if(i != 0 || i != n || j == n)
                        {
                            T[i][j] +=  r*(Tpas[i-1][n] + Tpas[i+1][n] - 4*Tpas[i][n] + Tpas[i][n-1] + Tpas[i][n]);
                        }
                    }
                    
                    else
                    {
                        T[i][j] +=  r*(Tpas[i-1][j] + Tpas[i+1][j] - 4*Tpas[i][j] + Tpas[i][j-1] + Tpas[i][j+1]);
                    }
                }
            }
            
            for(int i1 = 0; i1<n; i1++)
            {
                for(int j1 = 0; j1<n; j1++)
                {
                    Tpas[i1][j1] = T[i1][j1];
                }
            }
        }
        
        outfile.close();
    }
    
    //Fronteras periodicas
    if(k == 2)
    {
        outfile.open("datosFrontera2.dat");
        
        for(int t = 0; t<max; t++)
        {
            if(t == t1 || t == t2 || t == t3)
            {
                for(int x = 0; x<n; x++)
                {
                    for(int y = 0; y<n; y++)
                    {
                        outfile<<T[x][y]<<" ";
                    }
                    
                    outfile<<endl;
                }
            }
            
            for(int i = 0; i<n; i++)
            {
                for(int j = 0; j<n; j++)
                {
                    
                    if(i == 0 || i == n || j == 0 || j == n)
                    {
                        if(j != 0 || j != n || i == 0)
                        {
                            T[i][j] +=  r*(Tpas[n][j] + Tpas[1][j] - 4*Tpas[0][j] + Tpas[0][j-1] + Tpas[0][j+1]);
                        }
                        
                        else if(j != 0 || j != n || i == n)
                        {
                            T[i][j] +=  r*(Tpas[n-1][j] + Tpas[0][j] - 4*Tpas[n][j] + Tpas[n][j-1] + Tpas[n][j+1]);
                        }
                        
                        else if(i != 0 || i != n || j == 0)
                        {
                            T[i][j] +=  r*(Tpas[i-1][0] + Tpas[i+1][0] - 4*Tpas[i][0] + Tpas[i][n] + Tpas[i][1]);
                        }
                        
                        else if(i != 0 || i != n || j == n)
                        {
                            T[i][j] +=  r*(Tpas[i-1][n] + Tpas[i+1][n] - 4*Tpas[i][n] + Tpas[i][n-1] + Tpas[i][0]);
                        }
                    }
                    
                    else
                    {
                        T[i][j] +=  r*(Tpas[i-1][j] + Tpas[i+1][j] - 4*Tpas[i][j] + Tpas[i][j-1] + Tpas[i][j+1]);
                    }
                }
            }
            
            for(int i1 = 0; i1<n; i1++)
            {
                for(int j1 = 0; j1<n; j1++)
                {
                    Tpas[i1][j1] = T[i1][j1];
                }
            }
        }
        
        outfile.close();
    }
    
    //Froenteras fijas
    if(k == 3)
    {
        outfile.open("datosFrontera3.dat");
        
        for(int t = 0; t<max; t++)
        {
            if(t == t1 || t == t2 || t == t3)
            {
                for(int x = 0; x<n; x++)
                {
                    for(int y = 0; y<n; y++)
                    {
                        outfile<<T[x][y]<<" ";
                    }
                    
                    outfile<<endl;
                }
            }
            
            for(int i = 0; i<n; i++)
            {
                for(int j = 0; j<n; j++)
                {
                    
                    if(i == 0 || i == n || j == 0 || j == n)
                    {
                        T[i][j] = 0.0;
                    }
                    
                    else
                    {
                        T[i][j] +=  r*(Tpas[i-1][j] + Tpas[i+1][j] - 4*Tpas[i][j] + Tpas[i][j-1] + Tpas[i][j+1]);
                    }
                }
            }
            
            for(int i1 = 0; i1<n; i1++)
            {
                for(int j1 = 0; j1<n; j1++)
                {
                    Tpas[i1][j1] = T[i1][j1];
                }
            }
        }
        
        outfile.close();
    }
    
    else
    {
        cout<<"No se encontraron las condiciones de fronteras deseadas"
    }
}