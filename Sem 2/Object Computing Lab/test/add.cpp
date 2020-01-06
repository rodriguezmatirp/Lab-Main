#include<iostream>
using namespace std;

class operation
{
    int a,b;
    public :
    void getValues();
    int add();
};

void operation::getValues()
{
    cin>>a>>b;
}

int operation::add()
{
    return a+b;
}
int main()
{
    operation add;
    cout<<"enter the inputs"<<endl;
    add.getValues();
    cout<<"result "<<add.add();
    return 0;
}
