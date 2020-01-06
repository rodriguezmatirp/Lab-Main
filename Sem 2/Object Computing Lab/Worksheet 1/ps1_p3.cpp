#include<iostream>
using namespace std;

float fibonacci(float );

int main()
{
    float a;
    cout<<"enter the number\n";
    cin>>a;
    cout<<"fibonacci number of the number\n"<<fibonacci(a);
    return 0;
}
float fibonacci(float a)
{
    if(a==0)
    return 0;
    else if(a==1.0)
    return 1.0;
    else if(a>1.0)
    return fibonacci(a-1.0)+fibonacci(a-2.0);
}
