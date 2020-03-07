#include <bits/stdc++.h>
using namespace std;

class Person
{
    string name;
    int age;
    char gender;

public:
    Person() : name("\0"), age(0) {cout<<"Person constructor called\n";}
    Person(string name, int age, char gender) : name(name), age(age), gender(gender) {cout<<"Person constructor called\n";}
    void display();
};

void Person ::display()
{
    cout << "Name : " << name << endl;
    cout << "Age : " << age << endl;
    cout << "Gender : " << gender << endl;
}

class Student :virtual public Person
{
    string institute;

public:
    Student() : institute("\0") {}
    Student(string name, int age, char gender, string institute) : Person(name, age, gender), institute(institute) {cout<<"Student constructor called\n";}
    void display()
    {
        Person::display();
        cout << "Institute : " << institute << endl;
    }
};

class Employee : virtual public Person
{
    string company;

public:
    Employee() : company("\0") {}
    Employee(string name, int age, char gender, string company) : Person(name, age, gender), company(company) {cout<<"Employee constructor called\n";}
    void display()
    {
        Person::display();
        cout << "company : " << company << endl;
    };
};

class Parttime : public Student, Employee
{
public:
    Parttime(string name, int age, char gender, string company, string institute) : Employee(name, age, gender, company), Student(name, age, gender, institute) {}
    void display();
};

void Parttime ::display()
{
    Student::display();
    Employee::display();
}

int main()
{
    Parttime obj("Tarun Pritam", 18, 'm', "Google", "PSG Tech");
    obj.display();
    return 0;
}