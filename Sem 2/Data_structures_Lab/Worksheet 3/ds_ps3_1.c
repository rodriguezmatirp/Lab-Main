#include<iostream>
using namespace std;

int main()
{
    int a[50]={0};
    int n,i;
    cout<<"enter the scores of students";
    for(i=0;i<500;i++)
    {
        cin>>n;
        if(n>50)
        a[n-51]++;
        else
        continue;
    }
    for(i=0;i<50;i++)
        cout<<"the fequency of "<<i+51<<endl<<a[i];
}
