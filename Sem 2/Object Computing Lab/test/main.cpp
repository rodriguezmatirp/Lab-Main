#include <iostream>
#include "reactangle.h"

using namespace std;

int main()
{
    rectangle r;
    float l,b;
    cout<<"enter the length";
    cin>>l;
    cout<<endl<<"enter the breadth"<<endl;
    cin>>b;
    cout<<"area :"<<r.area(l,b);
    return 0;
}


