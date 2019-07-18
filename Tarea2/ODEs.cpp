#include <fstream>
#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;

typedef double F(double, double, double, double, double);

double f_vx(double , double , double, double, double);
double f_vy(double , double , double, double, double);
double f_x(double , double , double, double, double);
double f_y(double , double , double, double, double);

double G;
double M_sol;

void eulerSegOrden(F, F, F, F, double, double, double, double);
    
int main()
{
    //En masas solares, anios, y unidades astronomicas
    G = 39.478;
    M_sol = 1.0;
    
    double vx0 = -6.35;
    double vy0 = 0.606;
    double x0 = 0.1163;
    double y0 = 0.9772;
    
    eulerSegOrden(f_vx, f_vy, f_x, f_y, x0, y0, vx0, vy0);
    
    return 0;
}

double f_vx(double t_f_v, double x_f_v, double y_f_v, double vx_f_v, double vy_f_v)
{
    return vx_f_v;
}

double f_vy(double t_f_v, double x_f_v, double y_f_v, double vx_f_v, double vy_f_v)
{
    return vy_f_v;
}

double f_x(double t_f_x, double x_f_x, double y_f_x, double vx_f_x, double vy_f_x)
{
    return -x_f_x*G*M_sol/pow(pow(x_f_x, 2) + pow(y_f_x, 2), 1.5);
}

double f_y(double t_f_y, double x_f_y, double y_f_y, double vx_f_y, double vy_f_y)
{
    return -y_f_y*G*M_sol/pow(pow(x_f_y, 2) + pow(y_f_y, 2), 1.5);
}

void eulerSegOrden(F funVx, F funVy, F funX, F funY, double x_0, double y_0, double vx_0, double vy_0)
{
    double h = 0.01;
    
    double x = x_0;
    double y = y_0;
    double v_x = vx_0;
    double v_y = vy_0;
    ofstream outfile;
    outfile.open("datosEuler.dat");
    
    for(double t = 0.0; t < 20.0; t+=h)
    {
        outfile<<t<<" "<<x<<" "<<y<<" "<<v_x<<" "<<v_y<<endl;
        
        v_x += h*funX(t, x, y, v_x, v_y);
        v_y += h*funY(t, x, y, v_x, v_y);
        x += h*funVx(t, x, y, v_x, v_y);
        y += h*funVy(t, x, y, v_x, v_y);
    }
    
    outfile.close();
}