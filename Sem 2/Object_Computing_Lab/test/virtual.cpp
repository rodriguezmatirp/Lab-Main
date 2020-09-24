#include <iostream>
using namespace std;

class base
{
public:
    virtual void func()
    {
        cout << "Base Class\n";
    }
};

class derived  :public base
{
    public : 
    virtual void func()
    {
        cout<<"Derived class\n";
    }
};

int main()
{
    base* b;
    derived d;
    b = &d;
    b->func();
    d.func();
    return 0;
}