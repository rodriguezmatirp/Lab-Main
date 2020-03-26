#include<bits/stdc++.h>
using namespace std;

class RestaurantMeal
{
    protected:
    string food_name;
    float price_;
    public:
    RestaurantMeal() : food_name("\0"),price_(0){}
    RestaurantMeal(string name,float price = 0) : food_name(name),price_(price){}
    void get_data();
    void display();
};

void RestaurantMeal :: get_data()
{
    cout<<"Food name : "<<endl;
    cin>>food_name;
    cin.sync();
    cout<<"Price : "<<endl;
    cin>>price_;
}

void RestaurantMeal :: display()
{
    cout<<"Food name : "<<food_name<<endl;
    cout<<"Price : $"<<price_<<endl;
}

class HotelService
{
    protected:
    string service_name;
    float fee_;
    int room_no;
    public:
    HotelService() : service_name("\0"),room_no(0),fee_(0){}
    HotelService(string name,float fee = 0,int room = 0) : service_name(name),fee_(fee),room_no(room){}
    void get_data();
    void display();
};

void HotelService::get_data()
{
    cout<<"Service name : "<<endl;
    cin>>service_name;
    cin.sync();
    cout<<"Fee : "<<endl;
    cin>>fee_;
    cout<<"Room Number : "<<endl;
    cin>>room_no;
}

void HotelService :: display()
{
    cout<<"Service name : "<<service_name<<endl;
    cout<<"Fee : $"<<fee_<<endl;
    cout<<"Room Number : "<<room_no<<endl;
}

class RoomServiceMeal : public HotelService,public RestaurantMeal
{
    public:
    RoomServiceMeal(int room,string name,float cost) : HotelService("room service",4,room),RestaurantMeal(name,cost){}
    void display();
    void get_data();
};

void RoomServiceMeal ::display()
{
    RestaurantMeal::display();
    HotelService::display();
}

void RoomServiceMeal::get_data()
{
    RestaurantMeal::get_data();
}

int main()
{
    RoomServiceMeal C(1202,"steak dinner",19.99);
    C.display();
    return 0;
}