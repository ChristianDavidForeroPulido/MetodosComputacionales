#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

//COndicion inicial es de 0<x<0.75 y 1.25<x<2 vale 0, mientras que 0.75<x<1.25 vale 2. Y v=1.

int main()
{
    double a = 0.0;
    double b = 2.0;
    double v = 1.0;
    int n = 1000;
    
    int m = 500;
    
    double x[n];
    
    for(int i = 0; i < n; i++)
    {
        x[i] = a + i*((b-a)/(n-1));
    }
    
    double y[n];
    double yPasado[n];
    
    for(int i = 0; i < n; i++)
    {
        if(i > n*0.75/(b-a) && i < n*1.25/(b-a) )
        {
            y[i] = 2.0;
            yPasado[i] = 0.0;
        }
        
        else
        {
            y[i] = 0.0;
            yPasado[i] = 0.0;
        }
    }
    
    for(int i = 0; i < n; i++)
    
    double yFrontera0 = 0.0;
    
    double yFronteraN = 0.0;
    
    double deltaX = x[1]-x[0];
    
    double deltaT = (deltaX)/v;
    
    double tiempo = 0.0;
    
    ofstream outfile;
    outfile.open("datos.dat");
    
    
    //Con frontera ciclica, si la frontera fuera fija habria que cambiar el if y agregar una restriccion a el ultimo dato
    for(int j = 0; j < m; j++)
    {
        //Primera columna es el tiempo, y el resto son las y en las posiciones respectivas
        outfile<<tiempo<<" ";
        
        tiempo += deltaT;
        
        for(int i = 0; i < n; i++)
        {
            if(i==0)
            {
                yPasado[i] = y[i];
                y[i] += v*(deltaT/deltaX)*(yPasado[1] - yPasado[n])/2.0;
            }
            
            else if(i==n)
            {
                yPasado[i] = y[i];
                y[i] += v*(deltaT/deltaX)*(yPasado[0] - yPasado[n-1])/2.0;
            }
        
            else
            {
                yPasado[i] = y[i];
                
                if(y[i] + v*(deltaT/deltaX)*(yPasado[i+1] - yPasado[i-1])/2.0 < 2.0 && y[i] + v*(deltaT/deltaX)*(yPasado[i+1] - yPasado[i-1])/2 > 0.0)
                {
                    y[i] += v*(deltaT/deltaX)*(yPasado[i+1] - yPasado[i-1])/2.0;
                }
                
                else if(y[i] + v*(deltaT/deltaX)*(yPasado[i+1] - yPasado[i-1])/2.0 >= 2.0)
                {
                    y[i] = 2;
                }
                
                else
                {
                    y[i] = 0;
                }
            }
        
            outfile<<y[i]<<" ";
        }
        
        outfile<<endl;
    }
    
    outfile.close();
}