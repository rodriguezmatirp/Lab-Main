#include<iostream>
using namespace std;

int main()
{
     int n,i,x,a[100];
     cout<<"enter the no.of elements and the elements\n";
     cin>>n;
     for(i=0;i<n;i++)
     cin>>a[i];
     cout<<"enter the element you wanna search\n";
     cin>>x;
     for(i=0;i<n;i++)
     {
         if(x>a[n/2])
         i=n/2;
         else if(x<a[n/2])
         n=n/2;
     }
}
