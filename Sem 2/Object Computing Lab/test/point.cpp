#include <iostream>
using namespace std;

class point
{
public:
    int x_co, y_co;
    void set();
    bool isorigin();
    void display();
    point diff(point);
    point();
    point(int, int);
};

point::point()
{
    x_co = 0;
    y_co = 0;
}
point::point(int x, int y)
{
    this->x_co = x;
    this->y_co = y;
}
void point::set()
{

    x_co = 0;
    y_co = 0;
}
bool point::isorigin()
{
    if (x_co == 0 && y_co == 0)
        return true;
    else
        return false;
}
void point::display()
{
    cout << "x co: " << x_co << endl;
    cout << "y co: " << y_co << endl;
}

int main()
{
    point p1, p2;
    p1.x_co = 10;
    p2.y_co = 20; 
    p1.display();
    p1.set();
    cout<<p2.isorigin()<<"\n";
    p2.display();
    point p3;
    point p4(5, 6);
    cout<< "after constructors\n";
    p3.display();
    p4.display();

    return 0;
}
