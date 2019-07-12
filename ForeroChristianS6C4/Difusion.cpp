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
void solucionDifusionFronteraLibreFuente();
void solucionDifusionFronteraPeriodicaFuente();
void solucionDifusionFronteraFijaFuente();

int main()
{ 
    solucionDifusionFronteraLibre();
    solucionDifusionFronteraPeriodica();
    solucionDifusionFronteraFija();
    solucionDifusionFronteraLibreFuente();
    solucionDifusionFronteraPeriodicaFuente();
    solucionDifusionFronteraFijaFuente();
}

void solucionDifusionFronteraLibre()
{
    double L = 1;

    double v = 0.0001;

    double dx = 0.01;

    double dt = 0.25*(dx*dx)/v;
    
    int t1 = 0;
    int t2 = int(100/dt);
    int t3 = int(2500/dt);

    int n = int(L/dx) + 1;
    
    double TempProm[t3+1];
    
    for(int g = 0; g<t3+1;g++)
    {
        TempProm[g] = 0.0;
    }
    
    double tiempo[t3+1];

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
                TempProm[t] += Tpas[i1][j1]/(n*n);
                Tpas[i1][j1] = T[i1][j1];
                
            }
        }
        
        tiempo[t] = t*dt;
    }
    
    outfile.close();
    
    outfile.open("TemperaturaPromedioFronteraLibre.dat");
    
    for(int k = 0; k < t3 ; k++)
    {
        outfile<<tiempo[k]<<" "<<TempProm[k]<<endl;
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
    
    int t1 = 0;
    int t2 = int(100/dt);
    int t3 = int(2500/dt);
    
    double TempProm[t3+1];
    for(int g = 0; g<t3+1;g++)
    {
        TempProm[g] = 0.0;
    }
    
    double tiempo[t3+1];

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
                TempProm[t] += Tpas[i1][j1]/(n*n);
                Tpas[i1][j1] = T[i1][j1];
            }
        }
        
        tiempo[t] = t*dt;
    }
    
    outfile.close();
    
    outfile.open("TemperaturaPromedioFronteraPeriodica.dat");
    
    for(int k = 0; k < t3 ; k++)
    {
        outfile<<tiempo[k]<<" "<<TempProm[k]<<endl;
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
    
    int t1 = 0;
    int t2 = int(100/dt);
    int t3 = int(2500/dt);
    
    double TempProm[t3+1];
    
    for(int g = 0; g<t3+1;g++)
    {
        TempProm[g] = 0.0;
    }
    
    double tiempo[t3+1];

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
                TempProm[t] += Tpas[i1][j1]/(n*n);
                Tpas[i1][j1] = T[i1][j1];
            }
        }
        
        tiempo[t] = t*dt;
    }
    
    outfile.close();
    
    
    outfile.open("TemperaturaPromedioFronteraFija.dat");
    
    for(int k = 0; k < t3+1 ; k++)
    {
        outfile<<tiempo[k]<<" "<<TempProm[k]<<endl;
    }
    
    outfile.close();
}

void solucionDifusionFronteraLibreFuente()
{
    double L = 1;

    double v = 0.0001;

    double dx = 0.01;

    double dt = 0.25*(dx*dx)/v;
    
    int t1 = 0;
    int t2 = int(100/dt);
    int t3 = int(2500/dt);

    int n = int(L/dx) + 1;
    
    double TempProm[t3+1];
    
    for(int g = 0; g<t3+1;g++)
    {
        TempProm[g] = 0.0;
    }
    
    double tiempo[t3+1];

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

    double r = 0.5*v*dt/(dx*dx);
    
    outfile.open("datosFrontera1Fuente.dat");
    
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
                if(i>0.40*n && i<0.60*n && j>0.20*n && j<0.40*n)
                {
                    T[i][j] = 100.0;
                }
                
                else if(i == 0 && j == 0)
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
                TempProm[t] += Tpas[i1][j1]/(n*n);
                Tpas[i1][j1] = T[i1][j1];
                
            }
        }
        
        tiempo[t] = t*dt;
    }
    
    outfile.close();
    
    outfile.open("TemperaturaPromedioFronteraLibreFuente.dat");
    
    for(int k = 0; k < t3 ; k++)
    {
        outfile<<tiempo[k]<<" "<<TempProm[k]<<endl;
    }
    
    outfile.close();
}

void solucionDifusionFronteraPeriodicaFuente()
{
    double L = 1;

    double v = 0.0001;

    double dx = 0.01;

    double dt = 0.25*(dx*dx)/v;
    
    int t1 = 0;
    int t2 = int(100/dt);
    int t3 = int(2500/dt);

    int n = int(L/dx) + 1;
    
    double TempProm[t3+1];
    
    for(int g = 0; g<t3+1;g++)
    {
        TempProm[g] = 0.0;
    }
    
    double tiempo[t3+1];

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

    double r = 0.5*v*dt/(dx*dx);
    
    outfile.open("datosFrontera2Fuente.dat");
    
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
                if(i>0.40*n && i<0.60*n && j>0.20*n && j<0.40*n)
                {
                    T[i][j] = 100.0;
                }
                
                else if(i == 0 && j == 0)
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
                TempProm[t] += Tpas[i1][j1]/(n*n);
                Tpas[i1][j1] = T[i1][j1];
                
            }
        }
        
        tiempo[t] = t*dt;
    }
    
    outfile.close();
    
    outfile.open("TemperaturaPromedioFronteraPeriodicaFuente.dat");
    
    for(int k = 0; k < t3 ; k++)
    {
        outfile<<tiempo[k]<<" "<<TempProm[k]<<endl;
    }
    
    outfile.close();
}

void solucionDifusionFronteraFijaFuente()
{
    double L = 1;

    double v = 0.0001;

    double dx = 0.01;

    double dt = 0.25*(dx*dx)/v;
    
    int t1 = 0;
    int t2 = int(100/dt);
    int t3 = int(2500/dt);

    int n = int(L/dx) + 1;
    
    double TempProm[t3+1];
    
    for(int g = 0; g<t3+1;g++)
    {
        TempProm[g] = 0.0;
    }
    
    double tiempo[t3+1];

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

    double r = 0.5*v*dt/(dx*dx);
    
    outfile.open("datosFrontera3Fuente.dat");
    
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
                if(i>0.40*n && i<0.60*n && j>0.20*n && j<0.40*n)
                {
                    T[i][j] = 100.0;
                }
                
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
                TempProm[t] += Tpas[i1][j1]/(n*n);
                Tpas[i1][j1] = T[i1][j1];
                
            }
        }
        
        tiempo[t] = t*dt;
    }
    
    outfile.close();
    
    outfile.open("TemperaturaPromedioFronteraFijaFuente.dat");
    
    for(int k = 0; k < t3 ; k++)
    {
        outfile<<tiempo[k]<<" "<<TempProm[k]<<endl;
    }
    
    outfile.close();
}