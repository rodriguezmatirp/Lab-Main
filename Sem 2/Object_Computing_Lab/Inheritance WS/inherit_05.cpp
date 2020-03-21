#include<bits/stdc++.h>
using namespace std;

class Investment
{
    int initial_,current_;
    int profit_;
    float profit_percent;
    public:
    Investment() : initial_(0),current_(0),profit_(0),profit_percent(0){}
    Investment(int initial,int current):initial_(initial),current_(current),profit_(current-initial),profit_percent(profit_/initial){}
    void display();
};

void Investment :: display()
{
    cout<<"Initial : "<<initial_<<endl;
    cout<<"Current : "<<current_<<endl;
    cout<<"Profit : "<<profit_<<endl;
    cout<<"Profit percentage : "<<profit_percent<<" % "<<endl;
}

class House
{
    string address_;
    float sq_feet;
    public:
    House() : address_("\0"),sq_feet(0){}
    House(string address,float sq_feet) : address_(address),sq_feet(sq_feet){}
    void display();
};

void House::display()
{
    cout<<"Address : "<<address_<<endl;
    cout<<"Square Feet : "<<sq_feet<<endl;
}

class HouseThatIsAnInvestment : public House,public Investment
{
    public:
    HouseThatIsAnInvestment(int initial,int current,string address,float sq_feet) : Investment(initial,current),House(address,sq_feet){}
    void display();
};

void HouseThatIsAnInvestment::display()
{
    Investment::display();
    House::display();
}

int main()
{
    HouseThatIsAnInvestment H(20,3000,"Dindigul,Tamil Nadu",2000.58);
    H.display();
    return 0;
}