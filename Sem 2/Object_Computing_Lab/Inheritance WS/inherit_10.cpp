#include <bits/stdc++.h>
using namespace std;

class Worker
{
protected:
    string name_;
    float sal_rate;
    float hours_;

public:
    Worker() : sal_rate(0) {}
    Worker(string name, float rate) : name_(name), sal_rate(rate) {}
    virtual float compute_pay() = 0;
    void display();
    void get_data();
};

void Worker ::get_data()
{
    cin.sync();
    cout << "Name : " << endl;
    cin >> name_;
    cout << "Salary Rate : " << endl;
    cin >> sal_rate;
    cout << "Hours : " << endl;
    cin >> hours_;
}

void Worker ::display()
{
    cout << "Name : " << name_ << endl;
    cout << "Salary Rate : " << sal_rate << endl;
    cout << "Hours : " << hours_ << endl;
    cout << "Weekly Wage : " << compute_pay() << endl;
}

class HourlyWorker : public Worker
{
public:
    float compute_pay();
};

float HourlyWorker::compute_pay()
{
    if (Worker::hours_ <= 40)
        return hours_ * sal_rate;
    return hours_ * sal_rate + (hours_ - 40) * sal_rate;
}

class SalariedWorker : public Worker
{
public:
    float compute_pay();
};

float SalariedWorker::compute_pay()
{
    return hours_ * sal_rate;
}

int main()
{
    Worker *W;
    HourlyWorker H;
    SalariedWorker S;
    W = &H;
    W->get_data();
    W = &S;
    W->get_data();
    H.display();
    S.display();
    return 0;
}