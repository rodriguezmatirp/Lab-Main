#include<bits/stdc++.h>
using namespace std;

class Rectangle
{
    int length,width;
    public:
    Rectangle() : length(0),width(0){}
    Rectangle(int l,int b):length(l),width(b){}
    void setData();
    void displayData();
    int area();
};

int Rectangle::area()
{
    return length*width;
}

void Rectangle ::setData()
{
    cout<<"Length : "<<endl;
    cin>>length;
    cout<<"Breadth : "<<endl;
    cin>>width;
}

void Rectangle ::displayData()
{
    cout<<"Length : "<<length<<endl;
    cout<<"Width : "<<width<<endl;
}

class Block : public Rectangle
{
    int height;
    public:
    Block() : Rectangle(),height(0){}
    Block(int l,int b,int h) : Rectangle(l,b),height(h){}
    void setData();
    void displayData();
    int area();
};

int Block::area()
{
    return Rectangle::area()*height;
}

void Block :: setData()
{
    Rectangle::setData();
    cout<<"Height : "<<endl;
    cin>>height;
}

void Block::displayData()
{
    Rectangle ::displayData();
    cout<<"Height : "<<height<<endl;
}

int main()
{
    Rectangle R(3,4);
    R.displayData();
    cout<<"Area : " << R.area()<<endl;
    Block B;
    B.setData();
    B.displayData();
    cout<<"Volume : " <<B.area();
    return 0;
}