#include<iostream>
#include "stdlib.h"

using namespace std;

class stack
{
        public:
                int top;
                int size;
                int *stack_a;
                int push(int element,int *p,int &top);
                int pop(int *p,int &top);
                void display_from_bottom();
                void display_from_top(int *p);
                void count();
                stack()
                {
                        top=-1;
                        size=20;
                        stack_a=new int[20];
                }
};

int stack::push(int element,int* p,int& top)
{
        if(top>=size-1)
        cout<<"stack overflow";
        else
        {
                top=top+1;
                p[top]=element;
                return 1;
        }
        return 0;
}

int stack::pop(int *p,int &top)
{
     int element;
        if(top==-1)
        cout<<"stack underflow";
        else
        {
                element=p[top];
                top=top-1;
                return element;
        }
        return 0;
}

void stack:: display_from_top(int *p)
{
        int i=top;
        while(i!=-1)
        {
                cout<<pop(p,i)<<endl;
        }
}

void stack::display_from_bottom()
{
        int *array=new int[20];
        int i=top;
        int j=-1;
        while(i!=-1)
        {
                push(pop(stack_a,i),array,j);
        }
        display_from_top(array);
        delete array;
}

void stack::count()
{
        if(top>0)
        cout<<"The total elements present:"<<top+1<<endl;
        else
                cout<<"No elements\n";
}

int main()
{
        stack operate;
        int i,element;
        line :
        system("clear");
        cout<<"Choose the operations below\n";
        cout<<"1)Insert an element\n2)delete an element\n3)Display the stack from bottom\n4)Display the stack from top\n5)Count the elements\n6)Exit\n";
        cin>>i;
        switch(i)
        {
                case 1:cout<<"Enter the element\n";
                        cin>>element;
                        if(operate.push(element,operate.stack_a,operate.top))
                        cout<<"successful\n";
                        else
                        cout<<"unsuccessful\n";
                        goto line;
                case 2:if(operate.pop(operate.stack_a,operate.top))
                        cout<<"successful\n";
                        else
                        cout<<"unsuccessful\n";
                        goto line;
                case 3:operate.display_from_bottom();
                        goto line;
                case 4:operate.display_from_top(operate.stack_a);
                        goto line;
                case 5:operate.count();
                        goto line;
                case 6: _Exit(0);
                default :cout<<"Invalid input";
                        goto line;
        }
        return 0;
}
