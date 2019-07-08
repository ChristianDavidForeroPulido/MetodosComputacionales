#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

//COndicion inicial es de 0<x<0.75 y 1.25<x<2 vale 0, mientras que 0.75<x<1.25 vale 2. Y v=1.

int main()
{
    
}

//el entero 0 para condiciones de frontera periodicas, para libres 1, 2 para fijas en y=0.
void adveccionSiguientePDE(double amplitudes[], double a, doubole b, double vec, doble deltaT, int f)
{
    int n = amplitudes.lenght();
    double deltaX = (b-a)/n;
    double amplitudesPasado[n] = amplitudes;
    double ampXInicial;
    
    if(f == 0)
    {
        ampXInicial = amplitudes[n];
    }
    
    else if(f == 1)
    {
        ampXInicial = amplitudes[0];
    }
    
    else
    {
        ampXInicial = 0.0;
    }
    
    amplitudes[0] = vec*(deltaT/deltaX)*(amplitudes[0]-ampXInicial);
        
    for(int i = 1; i < n-1; i++)
    {
        amplitudes[i] = vec*(deltaT/deltaX)*(amplitudes[i]-amplitudes[i-1]);
    }
    
    
}