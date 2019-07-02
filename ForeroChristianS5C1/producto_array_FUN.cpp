#include <fstream>
#include <iostream>
using namespace std;

int productoPunto(int m1[], int m2[]){
    int prod = 0;
    cout<<"El producto punto de los arreglos es: "<<endl;
    for(int i=0; i<5; i++){
        prod += m1[i]*m2[i];
    }
    cout<<prod<<endl;
}

void multiplicar(int m1[], int m2[]){
    int mult[5];
    cout<<"La multiplicacion termino a termino de los arreglos es: "<<endl;
    for(int i=0; i<5; i++){
        mult[i] = m1[i]*m2[i];
        cout<<mult[i]<<endl;
    }
}

int main(){
    
    int a[5] = {1,2,3,4,5};
    int b[5] = {10,20,30,40,50};
    
    multiplicar(a,b);
    productoPunto(a, b);
    
    return 0;
}