#include <fstream>
#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;

typedef double F(double, double, double);

double f_v(double , double , double, double);
double f_x(double , double , double, double);
double f_y(double , double , double, double);
void leapFrogSegOrden(F, F, double, double, double, double, double);
void eulerSegOrden()
    
int main()
{
    return 0
}pow()

double f_v(double t_f_v, double x_f_v, double y_f_v, double v_f_v)
{
    return v_f_v;
}

double f_x(double t_f_x, double x_f_x, double y_f_x, double v_f_x)
{
    return -x_f_x*G*M_sol/pow(pow(x_f_x, 2) + pow(y_f_x, 2), 1.5);
}

double f_y(double t_f_y, double x_f_y, double y_f_y, double v_f_y)
{
    return -y_f_y*G*M_sol/pow(pow(x_f_y, 2) + pow(y_f_y, 2), 1.5);
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