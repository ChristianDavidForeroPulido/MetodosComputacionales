#include<iostream>
using namespace std;

int factorial(int n)
{
    if(n<0)
    {
        return 0;
    }
    
    else if(n==0)
    {
        return 1;
    }
    
    else
    {
        return n*factorial(n-1);
    }
}

int main(void)
{
    cout<<factorial(7);
    
    return 0;
}