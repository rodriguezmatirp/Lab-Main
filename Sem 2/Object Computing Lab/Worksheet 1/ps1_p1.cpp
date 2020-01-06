#include<iostream>
using namespace std;

float area(float);
float area(float,float);

int main()
{
    bool flag=true;
    float rad,sid1,sid2;
    float carea,rarea;
    cout<<sizeof(bool);
    cout<<flag;
    cout<<"enter the radius\n";
    cin>>rad;
    cout<<"enter the sides of rectangle\n";
    cin>>sid1>>sid2;
    carea=area(rad);
    rarea=area(sid1,sid2);
    cout<<"circle area: "<<carea<<endl;
    cout<<"rectangle area: "<<rarea<<endl;
    cout<<area(2.5f)<<endl;
    return 0;
}
float area(float rad)
{
    float area;
    area=3.14*rad*rad;
    return area;
}

float area(float sid1,float sid2)
{
    int area;
    area=sid1*sid2;
    return area;
}
