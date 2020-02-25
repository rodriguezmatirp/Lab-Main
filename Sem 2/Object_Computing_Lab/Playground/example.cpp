#include<bits/stdc++.h>
using namespace std;

class Example
{
    int x;
    public:
    Example(){x= 10;}
};

int main()
{
    Example e;
    int *x = (int*)&e;
    cout<<*x;
    return 0;
}