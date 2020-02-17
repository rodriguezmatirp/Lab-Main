#include <bits/stdc++.h>
using namespace std;

class Time
{
    int hour_;
    int minute_;
    int second_;

public:
    Time()
    {
        hour_ = 0;
        minute_ = 0;
        second_ = 0;
    };
    Time(int hr, int min, int sec)
    {
        hour_ = hr;
        minute_ = min;
        second_ = sec;
    };
    void printTime();
    Time operator+(const Time &);
    bool operator<(const Time &);
    friend bool checkHour(int);
    friend bool checkMinute(int);
    friend bool checkSecond(int);
};

bool checkHour(int hour)
{
    if (hour > 24)
        return 1;
    return 0;
}

bool checkMinute(int min)
{
    if (min > 60)
        return 1;
    return 0;
}

bool checkSecond(int sec)
{
    if (sec > 60)
        return 1;
    return 0;
}

void Time::printTime()
{
    cout << "Time : " << hour_ << " : " << minute_ << " : " << second_ << endl;
}

Time Time::operator+(const Time &obj)
{
    Time t;
    t.hour_ = hour_ + obj.hour_;
    if (checkHour(t.hour_))
        t.hour_ = t.hour_ % 24;
    t.minute_ = minute_ + obj.minute_;
    if (checkMinute(t.minute_))
    {
        t.minute_ %= 60;
        t.hour_ += 1;
    }
    if (checkHour(t.hour_))
        t.hour_ %= 24;
    t.second_ = second_ + obj.second_;
    if (checkSecond(t.second_))
    {
        t.second_ %= 60;
        t.minute_ += 1;
    }
    if (checkMinute(t.minute_))
    {
        t.minute_ %= 60;
        t.hour_ += 1;
    }
    if (checkHour(t.hour_))
        t.hour_ %= 24;
    return t;
}

bool Time::operator<(const Time &obj)
{
    if (obj.hour_ > hour_)
        return true;
    else if (obj.hour_ == hour_)
    {
        if (obj.minute_ > minute_)
            return true;
        else if (obj.minute_ == minute_)
        {
            if (obj.second_ > second_)
                return true;
            else if (obj.second_ == second_)
            {
                cout << "Equal time\n";
                return true;
            }
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

int main()
{
    Time t;
    Time t1(3, 45, 50);
    Time t2(4, 43, 27);
    t = t1 + t2;
    t.printTime();
    if (t1 < t2)
        cout << "success\n";
    return 0;
}