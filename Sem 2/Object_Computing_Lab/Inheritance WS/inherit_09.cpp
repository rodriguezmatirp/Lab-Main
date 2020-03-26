#include <bits/stdc++.h>
using namespace std;

class Computer
{
protected:
    int memory_size;
    string proc_name;
    int net_add;

public:
    Computer() : memory_size(0),net_add(0) {}
    Computer(int size, int add, string name) : memory_size(size), proc_name(name), net_add(add) {}
    void display();
    friend bool checkadd();
};

void Computer ::display()
{
    cout << "Memory Size : " << memory_size << endl;
    cout << "Processor : " << proc_name << endl;
    cout << "Network Address : " << net_add << endl;
}

class Laptop : public Computer
{
protected:
    float weight_;

public:
    Laptop() : Computer(), weight_(0) {}
    Laptop(string name, int add, int size, float wei) : Computer(size, add, name), weight_(wei) {}
    void display();
    friend bool checkadd();
};

void Laptop ::display()
{
    Computer ::display();
    cout << "Weight : " << weight_ << endl;
}

class Palmtop : public Computer, public Laptop
{
    float width_;
    float height_;

public:
    Palmtop() : Laptop(), height_(0), width_(0) {}
    Palmtop(string name, int add, int size, float w, float h, float wid) : Laptop(name, add, size, w), width_(wid), height_(h) {}
    void display();
    friend bool checkadd();
};

void Palmtop ::display()
{
    Laptop::display();
    cout << "Height : " << height_ << endl;
    cout << "Width : " << width_ << endl;
}

// bool checkadd()
// {
//     if(Computer :: net_add)
//         return true;
//     return true;
// }
