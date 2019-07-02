#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;

float funcion(float t){
    return cos(t);
}

float * derivada(float a, float b, int n){
    float der[n-1];
    float h = (b-a)/(n-1);
    float x = a;
    for(int i=0;i<n-1;i++){
        der[i] = (funcion(x+h) - funcion(x))/h;
        x += h;
    }
    float *p;
    p = der;
    return p;
}

int main(){
    float inic;
    float fina;
    int ene;
    
    cin>>inic;
    cin>>fina;
    cin>>ene;
    
    cout<<"los valor de las derivadas son: "<<endl;
    
    float *laDer;
    laDer = derivada(inic, fina, ene);
    
    for(int i=0;i<ene-1;i++){
        cout<<*laDer<<endl;
        laDer++;
    }
    
    return 0;
}