#include <bits/stdc++.h>
using namespace std;

class Animal
{
    int a;
public:
    virtual void Eat() { cout << "Generic Food\n"; }
};

class Cat : public Animal
{
    int b;
public:
    void Eat() { this->b =10; cout << "I eat Rat\n"; }
};

class base
{};

int main()
{
    Animal *a = new Animal;
    Cat *c = new Cat;
    a = c;
    a->Eat();
    c->Eat();
    cout << "c : " << sizeof(Cat) << endl;
    cout << "a : " << sizeof(Animal) << endl;
    Cat c1 , c2;
    cout<<"c : "<<sizeof(Cat)<<endl;
    cout<<"base : "<<sizeof(base);
    return 0;
}