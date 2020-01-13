#include "date.h"
using namespace std;

void date::getDate()
{
    getDate:
    cout<<"Enter the Month\n";
    cin>>month;
    cout<<"Enter the Day\n"
    cin>>day;
    cout<<"Enter the Year\n"
    cin>>year;
    cout<<"dd/mm/yyyy Format will be displayed\n";
    if(month>12||month<0||day>31||day<0||year>2030||year<1960)
    {
        cout<<"INVALID INPUT\n";
        goto getDate;
    }
}

void date::dispDate()
{
    cout<<day<<"/"<<month<<"/"<<year<<"\n";
}