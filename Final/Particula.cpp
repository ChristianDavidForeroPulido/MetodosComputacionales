#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

typedef double F(double, double, double, double, double);

double fVx(double , double , double, double, double);
double fVy(double , double , double, double, double);
double fx(double , double , double, double, double);
double fy(double , double , double, double, double);

double q;
double B;
double m;

void rungeKutta(F, F, F, F, double, double, double, double, double, double, double, double, int);

int main()
{
    q = 1.5;
    B = 3.0;
    m = 2.5;
    
    double x_0 = 1.0;
    double y_0 = 0.0;
    double z_0 = 0.0;
    double vx_0 = 0.0;
    double vy_0 = 1.0;
    double vz_0 = 2.0;
    
    
    rungeKutta(fx, fy, fVx, fVy, x_0, y_0, z_0, vx_0, vy_0, vz_0, 0.0, 10.0, 10000);
    
    return 0;
}

double fx(double tiempoParaX, double xParaX, double yParaX, double vxParaX, double vyParaX)
{
    return vxParaX;
}

double fy(double tiempoParaY, double xParaY, double yParaY, double vxParaY, double vyParaY)
{
    return vyParaY;
}

double fVx(double tiempoParaVX, double xParaVX, double yParaVX, double vxParaVX, double vyParaVX)
{
    return (q*B/m)*vyParaVX;
}

double fVy(double tiempoParaVY, double xParaVY, double yParaVY, double vxParaVY, double vyParaVY)
{
    return -(q*B/m)*vxParaVY;
}

void rungeKutta(F funX, F funY, F funVx, F funVy, double x0, double y0, double z0, double vx0, double vy0, double vz0, double tInicial, double tFinal, int n)
{
    double dt = (tFinal-tInicial)/(n-1);
    
    double vx = vx0;
    double vy = vy0;
    double vz = vz0;
    double x = x0;
    double y = y0;
    double z = z0;
    
    double vxP = vx0;
    double vyP = vy0;
    double xP = x0;
    double yP = y0;
    
    double vxK1;
    double vxK2;
    double vxK3;
    double vxK4;
    
    double vyK1;
    double vyK2;
    double vyK3;
    double vyK4;
    
    double xK1;
    double xK2;
    double xK3;
    double xK4;
    
    double yK1;
    double yK2;
    double yK3;
    double yK4;

    
    ofstream outfile;
    outfile.open("trayectoriaParticula.dat");
    
    for(double t = tInicial; t < tFinal; t+=dt)
    {        
        outfile<<t<<" "<<x<<" "<<y<<" "<<z<<" "<<" "<<vx<<" "<<vy<<" "<<vz<<endl;
        
        xP = x;
        yP = y;
        vxP = vx;
        vyP = vy;
        
        vxK1 = dt*funVx(t, xP, yP, vxP, vyP);
        vyK1 = dt*funVy(t, xP, yP, vxP, vyP);
        xK1 = dt*funX(t, xP, yP, vxP, vyP);
        yK1 = dt*funY(t, xP, yP, vxP, vyP);
        
        vxK2 = dt*funVx(t + 0.5*dt, xP + 0.5*xK1, yP + 0.5*yK1, vxP + 0.5*vxK1, vyP + 0.5*vyK1);
        vyK2 = dt*funVy(t + 0.5*dt, xP + 0.5*xK1, yP + 0.5*yK1, vxP + 0.5*vxK1, vyP + 0.5*vyK1);
        xK2 = dt*funX(t + 0.5*dt, xP + 0.5*xK1, yP + 0.5*yK1, vxP + 0.5*vxK1, vyP + 0.5*vyK1);
        yK2 = dt*funY(t + 0.5*dt, xP + 0.5*xK1, yP + 0.5*yK1, vxP + 0.5*vxK1, vyP + 0.5*vyK1);
        
        vxK3 = dt*funVx(t + 0.5*dt, xP + 0.5*xK2, yP + 0.5*yK2, vxP + 0.5*vxK2, vyP + 0.5*vyK2);
        vyK3 = dt*funVy(t + 0.5*dt, xP + 0.5*xK2, yP + 0.5*yK2, vxP + 0.5*vxK2, vyP + 0.5*vyK2);
        xK3 = dt*funX(t + 0.5*dt, xP + 0.5*xK2, yP + 0.5*yK2, vxP + 0.5*vxK2, vyP + 0.5*vyK2);
        yK3 = dt*funY(t + 0.5*dt, xP + 0.5*xK2, yP + 0.5*yK2, vxP + 0.5*vxK2, vyP + 0.5*vyK2);
        
        vxK4 = dt*funVx(t + dt, xP + xK3, yP + yK3, vxP + vxK3, vyP + vyK3);
        vyK4 = dt*funVy(t + dt, xP + xK3, yP + yK3, vxP + vxK3, vyP + vyK3);
        xK4 = dt*funX(t + dt, xP + xK3, yP + yK3, vxP + vxK3, vyP + vyK3);
        yK4 = dt*funY(t + dt, xP + xK3, yP + yK3, vxP + vxK3, vyP + vyK3);
        
        vx += (vxK1 + 2*vxK2 + 2*vxK3 + vxK4)/6;
        vy += (vyK1 + 2*vyK2 + 2*vyK3 + vyK4)/6;
        x += (xK1 + 2*xK2 + 2*xK3 + xK4)/6;
        y += (yK1 + 2*yK2 + 2*yK3 + yK4)/6;
        z += vz*dt;
    }
    
    outfile.close();
}