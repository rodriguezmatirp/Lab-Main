#include <bits/stdc++.h>
using namespace std;

class point
{
    int x;
    int y;
    string name;

public:
    point()
    {
        x = 0;
        y = 0;
    };
    point(int a, int b, const string name_)
    {
        x = a;
        y = b;
        name = name_;
    };
    friend istream &operator>>(istream &, point &);
    friend ostream &operator<<(ostream &, point &);
};

ostream &operator<<(ostream &out, point &obj)
{
    out << "x = " << obj.x << endl;
    out << "y = " << obj.y << endl;
    out << "name : " << obj.name << endl;
    return out;
}

istream &operator>>(istream &in, point &obj)
{
    cout << "value of x\n";
    in >> obj.x;
    cout << "value of y\n";
    in >> obj.y;
    in.ignore();
    cout<<"Enter your name\n";
    in >> obj.name;
    return in;
}

int main()
{
    point p;
    point q(3, 4,"pritam");
    cout << q;
    cin >> p;
    cout << p;
    return 0;
}