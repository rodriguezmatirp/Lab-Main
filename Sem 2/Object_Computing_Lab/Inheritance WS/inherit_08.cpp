#include<bits/stdc++.h>
using namespace std;

class Painting
{
    protected:
    float value_;
    public:
    string title_;
    string artist_name;
    Painting() : title_("\0"),artist_name("\0"),value_(0){}
    Painting(string title,string name,float val = 400) : title_(title),artist_name(name),value_(val){}
    void get_data();
    void display();
};

void Painting :: get_data()
{
    cout<<"Title : "<<endl;
    cin>>title_;
    cin.sync();
    cout<<"Artist Name : "<<endl;
    cin>>artist_name;
    cin.sync();
}

void Painting :: display()
{
    cout<<"Title : "<<title_<<endl;
    cout<<"Artist Name : "<<artist_name<<endl;
    cout<<"Value : $"<<value_<<endl;
}

class FamousPainting : public Painting
{
    public:
    FamousPainting() : Painting(){}
    FamousPainting(string title,string name) : Painting(title,name,25000){}
};

int main()
{
    Painting *p = new Painting;
    p->get_data();
    if(p->artist_name == "Monet")
    {
        FamousPainting *f = new FamousPainting(p->title_,p->artist_name);
        p = f;

    }
    p->display();
    return 0;
}