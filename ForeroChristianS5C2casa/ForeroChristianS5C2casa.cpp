#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

typedef double F(double, double);

double f(double x,double z)
{
    return -z;
}

void eulerPrimerOrden(F fun, double y0, double a, double b, double h)
{
    double y = y0;
    ofstream outfile;
    outfile.open("datosEuler.txt");
    for(double x = a; x < b; x+=h)
    {
        outfile <<x<<" "<<y<<endl;
        y += h*fun(x,y);
    }
    outfile.close();
}

void RKPrimerOrden(F fun, double y0, double a, double b, double h)
{
    double y = y0;
    ofstream outfile;
    outfile.open("datosRK.txt");
    
    for(double x = a; x < b; x+=h)
    {
        double k1 = h*fun(x, y);
        double k2 = h*fun(x + 0.5*h, y + 0.5*k1);
        double k3 = h*fun(x + 0.5*h, y + 0.5*k2);
        double k4 = h*fun(x + h, y + k3);
            
        outfile<<x<<" "<<y<<endl;
        double k_promedio = (k1 + 2.0*k2 + 2.0*k3 + k4)*(1.0/6.0);
        y += k_promedio;
    }
    outfile.close();
}

int main()
{
    eulerPrimerOrden(f, 1.0, 0.0, 2.0, 0.001);
    RKPrimerOrden(f, 1.0, 0.0, 2.0, 0.1);
}