#include<iostream>

using namespace std;

class point
{
        public:
        int x_co,y_co;
        void set();
        bool isorigin();
        void display();
        point diff(point);
};

void point::set()
{

    x_co=0;
    y_co=0;
}
bool point::isorigin()
{
    if(x_co==0&&y_co==0)
        return true;
    else
        return false;
}
void point::display()
{
    cout<<"x co: "<<x_co<<endl;
    cout<<"y co: "<<y_co<<endl;
}
class rectangle
{
    private:
        float l,b;
    public:

}
int main()
{
    point p1,p2;
    p1.x_co=10;
    p2.y_co=20;
    cout<<p1.display();
    cout<<p1.set();
    cout<<p1.isorigin();
    cout<<p1.display();

    return 0;
}
