#include "time.h"
using namespace std;

void time::getTime()
{
    getTime:
    Cout<<"24-Hour Format\n"
    cout<<"Enter the hours\n";
    cin>>hours;
    cout<<"Enter the minutes\n";
    cin>>minutes;
    cout<<"Enter the seconds\n";
    cin>>seconds;
    if(hours>24||hours<0||minutes>60||minutes<0||seconds>60||seconds<0)
    {
        cout<<"INPUT INVALID\n";
        goto getTime;
    }
}

void time::dispTime()
{
    cout<<hours<<":"<<minutes<<":"<<seconds;
    if(hours>12)
    cout<<"pm\n";
    else
    cout<<"am\n";
}