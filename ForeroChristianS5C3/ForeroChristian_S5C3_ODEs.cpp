#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

typedef double F(double, double, double);

double f1(double , double , double);
double f2(double , double , double);
void leapFrogSegOrden(F, F, double, double, double, double, double);
double k = 300.0/2.0;

int main()
{
    leapFrogSegOrden(f1, f2, 0.1, 0.0, 0.0, 5.0, 0.001);
    return 0;
}

double f1(double t_f1, double x_f1, double v_f1)
{
    return v_f1;
}

double f2(double t_f2, double x_f2, double v_f2)
{
    return -k*x_f2;
}

void eulerSegOrden(F fun1, F fun2, double x0, double v0, double a, double b, double h)
{
    double x = x0;
    double v = v0;
    ofstream outfile;
    outfile.open("datosEuler.dat");
    
    for(double t = a+h; t < b; t+=h)
    {
        outfile<<t<<" "<<x<<" "<<v<<endl;
        
        v += h*fun2(t, x, v);
        x += h*fun1(t, x, v);
    }
    
    outfile.close();
}



void leapFrogSegOrden(F fun1, F fun2, double x0, double v0, double a, double b, double h)
{
    double x = x0;
    double v = v - (h/2.0)*fun2(a, x, v);
    
    ofstream outfile;
    outfile.open("datosLeapFrog.dat");
    
    for(double t = a; t < b; t+=h)
    {
        outfile<<t<<" "<<x<<" "<<v<<endl;
        
        v += h*fun2(t, x, v);
        x += h*fun1(t, x, v);
    }
    
    outfile.close();
}