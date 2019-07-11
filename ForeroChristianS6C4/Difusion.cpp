#include <fstream>
#include <iomanip>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
using namespace std;

void solucionDifusionFronteraLibre();
void solucionDifusionFronteraPeriodica();
void solucionDifusionFronteraFija();

int main()
{ 
    solucionDifusionFronteraLibre();
    solucionDifusionFronteraPeriodica();
    solucionDifusionFronteraFija();
}

void solucionDifusionFronteraLibre()
{
    double L = 1;

    double v = 0.0001;

    double dx = 0.01;

    double dt = 0.25*(dx*dx)/v;

    int n = int(L/dx) + 1;

    double Tpas[n][n];
    double T[n][n];
    
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(i>0.40*n && i<0.60*n && j>0.20*n && j<0.40*n)
            {
                Tpas[i][j] = 100.0;
                T[i][j] = 100.0;
            }
            
            else
            {
                Tpas[i][j] = 50.0;
                T[i][j] = 50.0;
            }
        }
    }
    
    ofstream outfile;
    
    int t1 = 0;
    int t2 = int(100/dt);
    int t3 = int(2500/dt);
    
    double r = 0.5*v*dt/(dx*dx);
    
    outfile.open("datosFrontera1.dat");
    
    for(int t = 0; t<t3+1; t++)
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
                if(i == 0 && j == 0)
                {
                    T[i][j] +=  r*(Tpas[i][j] + Tpas[i+1][j] - 4*Tpas[i][j] + Tpas[i][j] + Tpas[i][j+1]);
                }
                
                else if(i == 0 && j == n-1)
                {
                    T[i][j] +=  r*(Tpas[i][j] + Tpas[i+1][j] - 4*Tpas[i][j] + Tpas[i][j-1] + Tpas[i][j]);
                }
                
                else if(i == n-1 && j == 0)
                {
                    T[i][j] +=  r*(Tpas[i-1][j] + Tpas[i][j] - 4*Tpas[i][j] + Tpas[i][j] + Tpas[i][j+1]);
                }
                
                else if(i == n-1 && j == n-1)
                {
                    T[i][j] +=  r*(Tpas[i-1][j] + Tpas[i][j] - 4*Tpas[i][j] + Tpas[i][j-1] + Tpas[i][j]);
                }
                
                else if(i == 0 && j != 0 && j != n-1)
                {
                    T[i][j] +=  r*(Tpas[i][j] + Tpas[i+1][j] - 4*Tpas[i][j] + Tpas[i][j-1] + Tpas[i][j+1]);
                }
                
                else if(i == n-1 && j != 0 && j != n-1)
                {
                    T[i][j] +=  r*(Tpas[i-1][j] + Tpas[i][j] - 4*Tpas[i][j] + Tpas[i][j-1] + Tpas[i][j+1]);
                }
                
                else if(i != 0 && i != n-1 && j == 0)
                {
                    T[i][j] +=  r*(Tpas[i-1][j] + Tpas[i+1][j] - 4*Tpas[i][j] + Tpas[i][j] + Tpas[i][j+1]);
                }
                
                else if(i != 0 && i != n-1 && j == n-1)
                {
                    T[i][j] +=  r*(Tpas[i-1][j] + Tpas[i+1][j] - 4*Tpas[i][j] + Tpas[i][j-1] + Tpas[i][j]);
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

void solucionDifusionFronteraPeriodica()
{
    double L = 1;

    double v = 0.0001;

    double dx = 0.01;

    double dt = 0.25*(dx*dx)/v;

    int n = int(L/dx) + 1;

    double Tpas[n][n];
    double T[n][n];
    
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(i>0.40*n && i<0.60*n && j>0.20*n && j<0.40*n)
            {
                Tpas[i][j] = 100.0;
                T[i][j] = 100.0;
            }
            
            else
            {
                Tpas[i][j] = 50.0;
                T[i][j] = 50.0;
            }
        }
    }
    
    ofstream outfile;
    
    int t1 = 0;
    int t2 = int(100/dt);
    int t3 = int(2500/dt);
    
    double r = 0.5*v*dt/(dx*dx);
    
    outfile.open("datosFrontera2.dat");
    
    for(int t = 0; t<t3+1; t++)
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
                if(i == 0 && j == 0)
                {
                    T[i][j] +=  r*(Tpas[n-1][j] + Tpas[i+1][j] - 4*Tpas[i][j] + Tpas[i][n-1] + Tpas[i][j+1]);
                }
                
                else if(i == 0 && j == n-1)
                {
                    T[i][j] +=  r*(Tpas[n-1][j] + Tpas[i+1][j] - 4*Tpas[i][j] + Tpas[i][j-1] + Tpas[i][0]);
                }
                
                else if(i == n-1 && j == 0)
                {
                    T[i][j] +=  r*(Tpas[i-1][j] + Tpas[0][j] - 4*Tpas[i][j] + Tpas[i][n-1] + Tpas[i][j+1]);
                }
                
                else if(i == n-1 && j == n-1)
                {
                    T[i][j] +=  r*(Tpas[i-1][j] + Tpas[0][j] - 4*Tpas[i][j] + Tpas[i][j-1] + Tpas[i][0]);
                }
                
                else if(i == 0 && j != 0 && j != n-1)
                {
                    T[i][j] +=  r*(Tpas[n-1][j] + Tpas[i+1][j] - 4*Tpas[i][j] + Tpas[i][j-1] + Tpas[i][j+1]);
                }
                
                else if(i == n-1 && j != 0 && j != n-1)
                {
                    T[i][j] +=  r*(Tpas[i-1][j] + Tpas[0][j] - 4*Tpas[i][j] + Tpas[i][j-1] + Tpas[i][j+1]);
                }
                
                else if(i != 0 && i != n-1 && j == 0)
                {
                    T[i][j] +=  r*(Tpas[i-1][j] + Tpas[i+1][j] - 4*Tpas[i][j] + Tpas[i][n-1] + Tpas[i][j+1]);
                }
                
                else if(i != 0 && i != n-1 && j == n-1)
                {
                    T[i][j] +=  r*(Tpas[i-1][j] + Tpas[i+1][j] - 4*Tpas[i][j] + Tpas[i][j-1] + Tpas[i][0]);
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

void solucionDifusionFronteraFija()
{
    double L = 1;

    double v = 0.0001;

    double dx = 0.01;

    double dt = 0.25*(dx*dx)/v;

    int n = int(L/dx) + 1;

    double Tpas[n][n];
    double T[n][n];
    
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(i>0.40*n && i<0.60*n && j>0.20*n && j<0.40*n)
            {
                Tpas[i][j] = 100.0;
                T[i][j] = 100.0;
            }
            
            else
            {
                Tpas[i][j] = 50.0;
                T[i][j] = 50.0;
            }
        }
    }
    
    ofstream outfile;
    
    int t1 = 0;
    int t2 = int(100/dt);
    int t3 = int(2500/dt);
    
    double r = 0.5*v*dt/(dx*dx);
    
    outfile.open("datosFrontera3.dat");
    
    for(int t = 0; t<t3+1; t++)
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
                if(i == 0 || j == 0 || i == n-1 || j == n-1)
                {
                    T[i][j] =  50.0;
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