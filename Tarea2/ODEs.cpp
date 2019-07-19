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
double M_tierra;

void eulerSegOrden(F, F, F, F, double, double, double, double, double);
void leapFrogSegOrden(F, F, F, F, double, double, double, double, double);
void rungeKuttaSegOrden(F, F, F, F, double, double, double, double, double);

int main()
{
    //En masas solares, anios, y unidades astronomicas
    G = 39.478;
    M_sol = 1.0;
    M_tierra = 3.00273*pow(10,-6);
    
    double vx0 = -6.35;
    double vy0 = 0.606;
    double x0 = 0.1163;
    double y0 = 0.9772;
    
    eulerSegOrden(f_vx, f_vy, f_x, f_y, x0, y0, vx0, vy0, 0.05);
    eulerSegOrden(f_vx, f_vy, f_x, f_y, x0, y0, vx0, vy0, 0.01);
    eulerSegOrden(f_vx, f_vy, f_x, f_y, x0, y0, vx0, vy0, 0.001);
    
    leapFrogSegOrden(f_vx, f_vy, f_x, f_y, x0, y0, vx0, vy0, 0.05);
    leapFrogSegOrden(f_vx, f_vy, f_x, f_y, x0, y0, vx0, vy0, 0.01);
    leapFrogSegOrden(f_vx, f_vy, f_x, f_y, x0, y0, vx0, vy0, 0.001);
    
    rungeKuttaSegOrden(f_vx, f_vy, f_x, f_y, x0, y0, vx0, vy0, 0.05);
    rungeKuttaSegOrden(f_vx, f_vy, f_x, f_y, x0, y0, vx0, vy0, 0.01);
    rungeKuttaSegOrden(f_vx, f_vy, f_x, f_y, x0, y0, vx0, vy0, 0.001);
    
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

void eulerSegOrden(F funVx, F funVy, F funX, F funY, double x_0, double y_0, double vx_0, double vy_0, double dt)
{
    double x = x_0;
    double y = y_0;
    double v_x = vx_0;
    double v_y = vy_0;
    
    double xPas = x_0;
    double yPas = y_0;
    double v_xPas = vx_0;
    double v_yPas = vy_0;
    
    double energia = (0.5*M_tierra*(pow(v_x,2) + pow(v_y,2))) - (G*M_sol*M_tierra+pow(pow(x,2) + pow(y,2), -0.5));
    double momento = M_tierra*((x*v_y) - (y*v_x));
    
    ofstream outfile;
    outfile.open("euler_dt="+to_string(dt)+".dat");
    
    for(double t = 0.0; t < 20.0; t+=dt)
    {
        outfile<<t<<" "<<x<<" "<<y<<" "<<v_x<<" "<<v_y<<" "<<energia<<" "<<momento<<endl;
        
        xPas = x;
        yPas = y;
        v_xPas = v_x;
        v_yPas = v_y;
        
        v_x += dt*funX(t, xPas, yPas, v_xPas, v_yPas);
        v_y += dt*funY(t, xPas, yPas, v_xPas, v_yPas);
        x += dt*funVx(t, xPas, yPas, v_xPas, v_yPas);
        y += dt*funVy(t, xPas, yPas, v_xPas, v_yPas);
        
        energia = (0.5*M_tierra*(pow(v_x,2) + pow(v_y,2))) - (G*M_sol*M_tierra+pow(pow(x,2) + pow(y,2), -0.5));
        momento = M_tierra*((x*v_y) - (y*v_x));
    }
    
    outfile.close();
}

void leapFrogSegOrden(F funVx, F funVy, F funX, F funY, double x_0, double y_0, double vx_0, double vy_0, double dt)
{
    double x = x_0;
    double y = y_0;
    double v_x = vx_0;
    double v_y = vy_0;
    
    double xPre = x_0;
    double yPre = y_0;
    double v_xPre = vx_0;
    double v_yPre = vy_0;
    
    double v_xPas = v_x - dt*funX(0.0, xPre, yPre, v_xPre, v_yPre);
    double v_yPas = v_y - dt*funY(0.0, xPre, yPre, v_xPre, v_yPre);
    double xPas = x - dt*funVx(0.0, xPre, yPre, v_xPre, v_yPre);
    double yPas = y - dt*funVy(0.0, xPre, yPre, v_xPre, v_yPre);
    
    double energia = (0.5*M_tierra*(pow(v_x,2) + pow(v_y,2))) - (G*M_sol*M_tierra+pow(pow(x,2) + pow(y,2), -0.5));
    double momento = M_tierra*((x*v_y) - (y*v_x));
    
    ofstream outfile;
    outfile.open("leapFrog_dt="+to_string(dt)+".dat");
    
    for(double t = 0.0; t < 20.0; t+=dt)
    {
        outfile<<t<<" "<<x<<" "<<y<<" "<<v_x<<" "<<v_y<<" "<<energia<<" "<<momento<<endl;
        
        xPas = xPre;
        yPas = yPre;
        v_xPas = v_xPre;
        v_yPas = v_yPre;
        
        xPre = x;
        yPre = y;
        v_xPre = v_x;
        v_yPre = v_y;
        
        v_x = v_xPas + 2*dt*funX(t, xPre, yPre, v_xPre, v_yPre);
        v_y = v_yPas + 2*dt*funY(t, xPre, yPre, v_xPre, v_yPre);
        x = xPas + 2*dt*funVx(t, xPre, yPre, v_xPre, v_yPre);
        y = yPas + 2*dt*funVy(t, xPre, yPre, v_xPre, v_yPre);
        
        energia = (0.5*M_tierra*(pow(v_x,2) + pow(v_y,2))) - (G*M_sol*M_tierra+pow(pow(x,2) + pow(y,2), -0.5));
        momento = M_tierra*((x*v_y) - (y*v_x));
    }
    
    outfile.close();
}

void rungeKuttaSegOrden(F funVx, F funVy, F funX, F funY, double x_0, double y_0, double vx_0, double vy_0, double dt)
{
    double x = x_0;
    double y = y_0;
    double v_x = vx_0;
    double v_y = vy_0;
    
    double xPas = x_0;
    double yPas = y_0;
    double v_xPas = vx_0;
    double v_yPas = vy_0;
    
    double vxK1;
    double vyK1;
    double xK1;
    double yK1;
    
    double vxK2;
    double vyK2;
    double xK2;
    double yK2;
    
    double vxK3;
    double vyK3;
    double xK3;
    double yK3;
    
    double vxK4;
    double vyK4;
    double xK4;
    double yK4;
    
    double energia = (0.5*M_tierra*(pow(v_x,2) + pow(v_y,2))) - (G*M_sol*M_tierra+pow(pow(x,2) + pow(y,2), -0.5));
    double momento = M_tierra*((x*v_y) - (y*v_x));
    
    ofstream outfile;
    outfile.open("rungeKutta_dt="+to_string(dt)+".dat");
    
    for(double t = 0.0; t < 20.0; t+=dt)
    {        
        outfile<<t<<" "<<x<<" "<<y<<" "<<v_x<<" "<<v_y<<" "<<energia<<" "<<momento<<endl;
        
        xPas = x;
        yPas = y;
        v_xPas = v_x;
        v_yPas = v_y;
        
        vxK1 = dt*funX(t, xPas, yPas, v_xPas, v_yPas);
        vyK1 = dt*funY(t, xPas, yPas, v_xPas, v_yPas);
        xK1 = dt*funVx(t, xPas, yPas, v_xPas, v_yPas);
        yK1 = dt*funVy(t, xPas, yPas, v_xPas, v_yPas);
        
        vxK2 = dt*funX(t + 0.5*dt, xPas + 0.5*xK1, yPas + 0.5*yK1, v_xPas + 0.5*vxK1, v_yPas + 0.5*vyK1);
        vyK2 = dt*funY(t + 0.5*dt, xPas + 0.5*xK1, yPas + 0.5*yK1, v_xPas + 0.5*vxK1, v_yPas + 0.5*vyK1);
        xK2 = dt*funVx(t + 0.5*dt, xPas + 0.5*xK1, yPas + 0.5*yK1, v_xPas + 0.5*vxK1, v_yPas + 0.5*vyK1);
        yK2 = dt*funVy(t + 0.5*dt, xPas + 0.5*xK1, yPas + 0.5*yK1, v_xPas + 0.5*vxK1, v_yPas + 0.5*vyK1);
        
        vxK3 = dt*funX(t + 0.5*dt, xPas + 0.5*xK2, yPas + 0.5*yK2, v_xPas + 0.5*vxK2, v_yPas + 0.5*vyK2);
        vyK3 = dt*funY(t + 0.5*dt, xPas + 0.5*xK2, yPas + 0.5*yK2, v_xPas + 0.5*vxK2, v_yPas + 0.5*vyK2);
        xK3 = dt*funVx(t + 0.5*dt, xPas + 0.5*xK2, yPas + 0.5*yK2, v_xPas + 0.5*vxK2, v_yPas + 0.5*vyK2);
        yK3 = dt*funVy(t + 0.5*dt, xPas + 0.5*xK2, yPas + 0.5*yK2, v_xPas + 0.5*vxK2, v_yPas + 0.5*vyK2);
        
        vxK4 = dt*funX(t + dt, xPas + xK3, yPas + yK3, v_xPas + vxK3, v_yPas + vyK3);
        vyK4 = dt*funY(t + dt, xPas + xK3, yPas + yK3, v_xPas + vxK3, v_yPas + vyK3);
        xK4 = dt*funVx(t + dt, xPas + xK3, yPas + yK3, v_xPas + vxK3, v_yPas + vyK3);
        yK4 = dt*funVy(t + dt, xPas + xK3, yPas + yK3, v_xPas + vxK3, v_yPas + vyK3);
        
        v_x += (vxK1 + 2*vxK2 + 2*vxK3 + vxK4)/6;
        v_y += (vyK1 + 2*vyK2 + 2*vyK3 + vyK4)/6;
        x += (xK1 + 2*xK2 + 2*xK3 + xK4)/6;
        y += (yK1 + 2*yK2 + 2*yK3 + yK4)/6;
        
        energia = (0.5*M_tierra*(pow(v_x,2) + pow(v_y,2))) - (G*M_sol*M_tierra+pow(pow(x,2) + pow(y,2), -0.5));
        momento = M_tierra*((x*v_y) - (y*v_x));
    }
    
    outfile.close();
}