#include<iostream>
using namespace std;

class merge
{
    public:
    float add(float,float);
    int add(int*,int *,int);
    int add(int,int);
    char add(char,char);
};
float merge::add(float x,float y)
{
    return x+y;
}
int merge::add(int x,int y)
{
    return x+y;
}
char merge::add(char x,char y)
{
    return x+y;
}
int merge::add(int *x,int *y,int n)
{
    int i;
    for(i=0;i<n;i++)
    cout<<x[i]+y[i]<<endl;
    return 0;
}
int main()
{
    int a,b,i,n;
    char c1,c2;
    float f1,f2;
    int x[10],y[10];
    merge m;
    cout<<"enter two decimal nnumbers\n";
    cin>>f1>>f2;
    cout<<"addition :"<<m.add(f1,f2)<<endl;
    cout<<"enter two characters\n";
    cin>>c1>>c2;
    cout<<"addition :"<<m.add(c1,c2)<<endl;
    cout<<"enter two nnumbers\n";
    cin>>a>>b;
    cout<<"addition :"<<m.add(a,b)<<endl;
    cout<<"enter no of elements and elements\n";
    cin>>n;
    for(i=0;i<n;i++)
    cin>>x[i];
    cout<<"enter elements of 2nd array\n";
    cin>>n;
    for(i=0;i<n;i++)
    cin>>y[i];
    cout<<"addition :";
    m.add(x,y,n);
    return 0;
}
