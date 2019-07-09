#include <fstream>
#include <iomanip>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
using namespace std;

int main()
{
    double A0 = 0.01;
    double L = 1.0;
    double c = 300.0;
    double dx = 0.005;
    double dt = 0.25*dx/c;
    
    int n = int(L/dx);
    int m = int(0.01/dt);
    
    double y[n];
    double yPasado[n];
    double yPresente[n];
    
    double yFrontIz = 0.0;
    double yFrontDe = 0.0;
    
    for(int i = 0; i < n; i++)
    {
        if(i < n/2)
        {
            y[i] = 2*((L/n)*i)*A0/L;
            yPasado[i] = 2*((L/n)*i)*A0/L;
            yPresente[i] = 2*((L/n)*i)*A0/L;
        }
        
        else
        {
            y[i] = 2*A0 - 2*((L/n)*i)*A0/L;
            yPasado[i] = 2*A0 - 2*((L/n)*i)*A0/L;
            yPresente[i] = 2*A0 - 2*((L/n)*i)*A0/L;
        }
    }
    
    double tiempo = 0.0;
    
    //Primer caso con extremos fijos
    ofstream outfile;
    outfile.open("datosCaso1.dat");
    
    for(int j = 0; j < m; j++)
    {
        //Primera columna es el tiempo, y el resto son las y en las posiciones respectivas
        outfile<<tiempo<<" ";
        
        tiempo += dt;
        
        for(int i = 0; i < n; i++)
        {
            outfile<<y[i]<<" ";
            
            if(i==0)
            {
                y[i] = (c*dt/dx)*(c*dt/dx)*(yPresente[1] + yFrontIz - 2*yPresente[0]) - yPasado[0] + 2*yPresente[0];
            }
            
            else if(i==n)
            {
                y[i] = (c*dt/dx)*(c*dt/dx)*(yFrontDe + yPresente[n-1] - 2*yPresente[n]) - yPasado[n] + 2*yPresente[n];
            }
        
            else
            {
                y[i] = (c*dt/dx)*(c*dt/dx)*(yPresente[i+1] + yPresente[i-1] - 2*yPresente[i]) - yPasado[i] + 2*yPresente[i];
            }
        }
        
        for(int l = 0; l < n; l++)
        {
            yPasado[l] = yPresente[l];
            yPresente[l] = y[l];
        }
        
        outfile<<endl;
    }
    
    outfile.close();
    
    yFrontIz = 0.0;
    yFrontDe = 0.0;
    
    for(int i = 0; i < n; i++)
    {
        if(i < n/2)
        {
            y[i] = 2*((L/n)*i)*A0/L;
            yPasado[i] = 2*((L/n)*i)*A0/L;
            yPresente[i] = 2*((L/n)*i)*A0/L;
        }
        
        else
        {
            y[i] = 2*A0 - 2*((L/n)*i)*A0/L;
            yPasado[i] = 2*A0 - 2*((L/n)*i)*A0/L;
            yPresente[i] = 2*A0 - 2*((L/n)*i)*A0/L;
        }
    }
    
    tiempo = 0.0;
    
    //Segundo caso con extremo izquierdo fijo y el derecho libre
    outfile.open("datosCaso2.dat");
    
    for(int j = 0; j < m; j++)
    {
        //Primera columna es el tiempo, y el resto son las y en las posiciones respectivas
        outfile<<tiempo<<" ";
        
        tiempo += dt;
        
        for(int i = 0; i < n; i++)
        {
            outfile<<y[i]<<" ";
            
            if(i==0)
            {
                y[i] = (c*dt/dx)*(c*dt/dx)*(yPresente[1] + yFrontIz - 2*yPresente[0]) - yPasado[0] + 2*yPresente[0];
            }
            
            else if(i==n)
            {
                y[i] = (c*dt/dx)*(c*dt/dx)*(yPresente[n] + yPresente[n-1] - 2*yPresente[n]) - yPasado[n] + 2*yPresente[n];
            }
        
            else
            {
                y[i] = (c*dt/dx)*(c*dt/dx)*(yPresente[i+1] + yPresente[i-1] - 2*yPresente[i]) - yPasado[i] + 2*yPresente[i];
            }
        }
        
        for(int l = 0; l < n; l++)
        {
            yPasado[l] = yPresente[l];
            yPresente[l] = y[l];
        }
        
        outfile<<endl;
    }
    
    outfile.close();
    
    yFrontIz = 0.0;
    yFrontDe = 0.0;
    
    for(int i = 0; i < n; i++)
    {
        if(i < n/2)
        {
            y[i] = 2*((L/n)*i)*A0/L;
            yPasado[i] = 2*((L/n)*i)*A0/L;
            yPresente[i] = 2*((L/n)*i)*A0/L;
        }
        
        else
        {
            y[i] = 2*A0 - 2*((L/n)*i)*A0/L;
            yPasado[i] = 2*A0 - 2*((L/n)*i)*A0/L;
            yPresente[i] = 2*A0 - 2*((L/n)*i)*A0/L;
        }
    }
    
    tiempo = 0.0;
    
    //Tercer caso con extremo izquierdo fijo y el derecho con movimiento armonico
    outfile.open("datosCaso3.dat");
    
    for(int j = 0; j < m; j++)
    {
        //Primera columna es el tiempo, y el resto son las y en las posiciones respectivas
        outfile<<tiempo<<" ";
        
        tiempo += dt;
        
        yFrontDe = A0*cos(3*c*tiempo*M_PI/L);
        
        for(int i = 0; i < n; i++)
        {
            outfile<<y[i]<<" ";
            
            if(i==0)
            {
                y[i] = (c*dt/dx)*(c*dt/dx)*(yPresente[1] + yFrontIz - 2*yPresente[0]) - yPasado[0] + 2*yPresente[0];
            }
            
            else if(i==n)
            {
                y[i] = (c*dt/dx)*(c*dt/dx)*(yFrontDe + yPresente[n-1] - 2*yPresente[n]) - yPasado[n] + 2*yPresente[n];
            }
        
            else
            {
                y[i] = (c*dt/dx)*(c*dt/dx)*(yPresente[i+1] + yPresente[i-1] - 2*yPresente[i]) - yPasado[i] + 2*yPresente[i];
            }
        }
        
        for(int l = 0; l < n; l++)
        {
            yPasado[l] = yPresente[l];
            yPresente[l] = y[l];
        }
        
        outfile<<endl;
    }
    
    outfile.close();
}