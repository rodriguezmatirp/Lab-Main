#include "participants.h"
#include "date.h"
#include<string>
using namespace std;

void dispEvent()
{
    cout<<"1) Event A\n2) Event B\n3) Event C\n4) Event D\n";
}

int event_naming(int i)
{
    if(i==1)
    strcpy(name_event,"Event A");
    else if(i==2)
    strcpy(name_event,"Event B");
    else if(i==3)
    strcpy(name_event,"Event C");
    else if(i==4)
    strcpy(name_event,"Event D");
    else 
    {
        cout<<"Invalid\n";
        return 0;
    }
    return 1;
}

void participants::getInput()
{
    int i;
    cout<<"Enter the Participant Name\n";
    cin.sync();
    getline(cin,name);
    cout<<"Enter the College Name\n"
    cin.sync();
    getline(cin,college);
    cout<<"Enter the Date Of Birth\n";
    DOB.getDate();
    getEvent:
    cout<<"Choose the Event\n";
    dispEvent();
    cin>>i;
    if(!event_naming(i))
    goto getEvent;
}

void participants::dispInfo()
{
    cout<<name<<"\n";
    cout<<college<<"\n";
    cout<<dispDate()<<"\n";
    cout<<name_event<<"\n";
}