#include<bits/stdc++.h>
using namespace std;

class Ship
{
    protected : 
    string name_;
    int est_year;
    public:
    Ship() : name_("\0"),est_year(0){}
    Ship(string name,int year) : name_(name) , est_year(year){}
    virtual void get_info();
    void modi_info();
    virtual void disp_info();
};

void Ship ::get_info()
{
    cout<<"Ship Name : "<<endl;
    cin>>name_;
    cin.sync();
    cout<<"Established year : "<<endl;
    cin>>est_year;
}

void Ship ::modi_info()
{
    int choice;
    cout<<"1.Change Name of the ship/n2.change the year of establishment/n";
    cin>>choice;
    cout<<"Enter : "<<endl;
    if(choice==1)
    {
        cin.sync();
        cin>>name_;
    }
    else if(choice ==2)
    cin>>est_year;
    else
    cout<<"Invalid choice/n";    
}

void Ship::disp_info()
{
    cout<<"Ship Name : "<<name_<<endl;
    cout<<"Year of establishment : "<<est_year<<endl;
}

class CruiseShip : public Ship
{
    int max_pass;
    public :
    CruiseShip() : Ship(),max_pass(0){}
    CruiseShip(string name,int year,int pass) : Ship(name,year),max_pass(pass){}
    void get_info();
    void disp_info();
};

void CruiseShip ::get_info()
{
    Ship ::get_info();
    cout<<"Maximum Passengers : "<<endl;
    cin>>max_pass;
}

void CruiseShip :: disp_info()
{
    cout<<"Ship : "<<name_;
    cout<<"Maximum passengers : "<<max_pass<<endl;
}

class CargoShip : public Ship
{
    int tonnage_cap;
    public:
    CargoShip() : Ship(),tonnage_cap(0){}
    CargoShip(string name,int year,int cap) : Ship(name,year),tonnage_cap(cap){}
    void get_info();
    void disp_info();
};

void CargoShip ::get_info()
{
    Ship ::get_info();
    cout<<"Tonnage capacity : "<<endl;
    cin>>tonnage_cap;
}

void CargoShip ::disp_info()
{
    cout<<"Ship Name : "<<name_<<endl;
    cout<<"Tonnage capacity : "<<tonnage_cap<<endl;
}

int main()
{
    CargoShip *cs1 = new CargoShip;
    CruiseShip cs2;
    Ship *s = new Ship;
    s = cs1;
    s->get_info();
    s->disp_info();
    return 0;
}