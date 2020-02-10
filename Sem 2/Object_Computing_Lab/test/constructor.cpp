#include<iostream>
using namespace std;

class Account
{
    char* name;
    public:
    const float int_rate;
    float balance;
    Account(const char *s,const float r,float b)
    {
        name=new char[30];
        *name=*s;
        int_rate=r;
        balance=b;
    }
};

int main()
{
    Account A1("tarunpritam",5.7,400.2);
    cout<<<A1.int_rate<<A1.balance;
    return 0;
}
