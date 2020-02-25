#include <bits\stdc++.h>
using namespace std;

class Point
{
public:
    int x, y;

    Point()
    {
        x = 0;
        y = 0;
    }
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
};
class Rational
{
    int num;
    int dnum;

public:
    Rational()
    {
        num = 0;
        dnum = 0;
    }
    Rational(int a, int b)
    {
        num = a;
        dnum = b;
    }
    Rational(Point p)
    {
        this->num = p.x;
        this->dnum = p.y;
    }
    void display()
    {
        cout<<"x : "<<num<<endl;
        cout<<"y : "<<dnum<<endl;
    }
    // void operator=(Point const &obj)
    // {
    //     this->num = obj.x;
    //     this->dnum = obj.y;
    // };
};

int main()
{
    Point p(3, 4);
    Rational *r;
    r = (Rational *)&p;
    (*r).display();
    Rational r1;
    Point P1;
    r1 = P1;
    r1.display();
    return 0;
}