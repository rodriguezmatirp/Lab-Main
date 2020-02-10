#include<bits/stdc++.h>
using namespace std;

int rear1=-1,rear2=-1,rear3=-1,front1=-1,front2=-1,front3=-1;
int size;

int gen_random(int random)
{
    return random%3;
}

int push(int *queue,int &rear,int elem)
{
    if(rear == size-1)
    {  
         cout<<"overflow";
        return -1;
    }
    else
    {
        rear=rear+1;
        queue[rear]=elem;
        return 1;
    }
}

int pop(int *queue,int &front,int rear)
{
    if(rear-front == 0)
    {
        cout<<"Underflow";
        return -1;
    }
    else
    {
        front++;
        return queue[front];
    }
}

void display(int *queue,int front,int rear)
{
    for(int i=front+1;i<rear;i++)
    cout<<pop(queue,front,rear)<<endl;
}

int supervisor_visit(int **queue)
{
    int *queue1 = new int [size];
    int *queue2 = new int [size];
    int *queue3 = new int [size];
    int temp1=-1,temp2=-1,temp3=-1,tempf1=-1,tempf2=-1,tempf3=-1;
    for(int i=0;i<rear1,i++)
        push(queue1,temp1,pop(queue[0],front1,rear1));
    for(int i=0;i<rear2;i++)
        push(queue2,temp2,pop(queue[1],front2,rear2));
    for(int i=0;i<rear3;i++)
        push(queue3,temp3,pop(queue[2],front3,rear3));
    cout<<"Queue 1: " ; display(queue1,tempf1,temp1); cout<<"Count : "<<temp1-tempf1;rear1=-1;front1=-1;
    cout<<"Queue 2: " ; display(queue2,tempf2,temp2); cout<<"Count : "<<temp2-tempf2;rear2=-1;front2=-1;
    cout<<"Queue 3: " ; display(queue3,tempf3,temp3); cout<<"Count : "<<temp3-tempf3;rear3=-1;front3=-1;
    for(int i=0;i<temp1,i++)
        push(queue[0],rear1,pop(queue1,tempf1,temp1));
    for(int i=0;i<temp2;i++)
        push(queue[1],rear2,pop(queue2,tempf2,temp2));
    for(int i=0;i<temp3;i++)
        push(queue[2],rear3,pop(queue3,tempf3,temp3));
    return 1;
}

int search_particular(int *queue,int front,int rear,int elem)
{
    static int x=1;
    int temp = rear;
    for(int i=0;i<temp;i++)
    {
        if(pop(queue,front,rear) == elem)
        {
            x++;
            return 1;
        }
    }
    return 0;
}

int search(int **queue)
{
    int elem;
    cout<<"Enter an element to be searched\n";
    cin>>elem;
    if(!(search_particular(queue[0],front1,rear1,elem)||search_particular(queue[1],front2,rear2,elem)||search_particular(queue[2],front3,rear3,elem)))
    cout<<"Not Found\nPlease try any valid Number";
    else 
    cout<<"Found !!\nPresent in Queue : "<<x;
    return 1;
}

int main
{
    int size,choice;
    cout<<"Enter the maximum storage of a queue\n";
    cin>>size;
    int **queues = new int* [3];
    for(int i=0;i<size;i++)
    queues[i] = new int [size];
    
    line:
    cout<<"1)New customer\n2)Supervisor visit\n3)Search\n4)Exit\n";
    switch (choice)
    {
        case 1: int random;
            cout<<"Enter a random number\n";
            cin>>random;
            if(gen_random(random)==0)
            push(queue[0],rear1,random);
            else if(gen_random(random)==1)
            push(queue[1],rear2,random);
            else 
            push(queue[2],rear3,random);
            goto line;
        case 2: supervisor_visit(queues);
                goto line;
        case 3: search(queues);
                goto line;
        case 4:exit(0);  
        
        default:cout<<"Enter a valid choice\n"
                goto line;            
    }


}