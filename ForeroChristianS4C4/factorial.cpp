#include<iostream>
using namespace std;

int main(void)
{
    int i;
    int fact=1;
    for(i=1;i<=7;i++)
    {
        fact = i*fact;
    }
    cout<<fact;
    
    return 0;
}