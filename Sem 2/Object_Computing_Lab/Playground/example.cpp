#include <iostream>
using namespace std;

class Computer
{
    protected:
        int size;
        string processor;
        int networkAddress;
    public:
        Computer():size(0),processor(),networkAddress(0){}
        friend ostream& operator << (ostream &, Computer &);
        friend istream& operator >> (istream &, Computer &);
        friend bool check();
};

class Laptop:public Computer
{
    protected:
        float weight;
    public:
        Laptop():weight(0){}
        friend ostream& operator << (ostream &, Laptop &);
        friend istream& operator >> (istream &, Laptop &);
        friend bool check();
};

class Palmtop:public Laptop
{
    float width, height;
    public:
        Palmtop():width(0),height(0){}
        friend ostream& operator << (ostream &, Palmtop &);
        friend istream& operator >> (istream &, Palmtop &);
        friend bool check();
};

istream& operator >> (istream &in, Computer &C)
{
    in >> C.size;
    cin.sync();
    in >> C.processor;
    in >> C.networkAddress;
    return in;
}

ostream& operator << (ostream &out, Computer &C)
{
    out << C.size << endl;
    out << C.processor << endl;
    out << C.networkAddress << endl;
    return out;
}

istream& operator >> (istream &in, Laptop &L)
{
    in >> L.size;
    cin.sync();
    in >> L.processor;
    in >> L.networkAddress;
    in >> L.weight;
    return in;
}

ostream& operator << (ostream &out, Laptop &L)
{
    out << L.size << endl;
    out << L.processor << endl;
    out << L.networkAddress << endl;
    out << L.weight << endl;
    return out;
}

istream& operator >> (istream &in, Palmtop &P)
{
    in >> P.size;
    cin.sync();
    in >> P.processor;
    in >> P.networkAddress;
    in >> P.weight;
    in >> P.width;
    in >> P.height;
    return in;
}

ostream& operator << (ostream &out, Palmtop &P)
{
    out << P.size << endl;
    out << P.processor << endl;
    out << P.networkAddress << endl;
    out << P.weight;
    out << P.width;
    out << P.height;
    return out;
}

bool check()
{
    if(networkAddress)
        return true;
    else
        return false;
}