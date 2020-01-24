#include<iostream>
#include<cstring>
using namespace std;

int viewstack(char *exp,char *stack,int l)
{
        char ch='\0';
        int check1=0,check2=0,check3=0,j=0;
        for(int i=0;i<l;i++)
        {
                if(exp[i]=='(')
                check1++;
                else if(exp[i]==')')
                check1--;
                else if(exp[i]=='{')
                check2++;
                else if(exp[i]=='{')
                check2--;
                else if(exp[i]=='[')
                check3++;
                else if(exp[i]==']')
                check3--;
        }
        if(!(check1+check2+check3))
        {
                for(int i=0;i<l;i++)
                {
                        if((exp[i]>='a'&&exp[i]<='z')||(exp[i]>='A'&&exp[i]<='Z'))
                        {       stack[j]=exp[i];
                                j++;
                                stack[j]=ch;
                                if(stack[j]!='\0')
                                j++;
                        }
                        else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='/'||exp[i]=='*')
                        ch=exp[i];
                }
                for(int i=0;i<l;i++)
                        cout<<stack[i];
                cout<<endl;
                return 1;
        }
        else
        {
                cout<<"invalid expression\n";
                return 0;
        }
}

int getvalues(char *stack,int *eval,int l)
{
        int j=0;
        for(int i=0;i<l;i++)
        {
                if((stack[i]>='a'&&stack[i]<='z')||(stack[i]>='A'&&stack[i]<='Z'))
                {
                        cout<<"Enter the value of "<<stack[i]<<endl;
                        cin>>eval[j];
                }
                else
                eval[j]=stack[i];
                j++;
        }
        return 0;
}

int push(int ele,int *arith,int &top)
{
        top=top+1;
        arith[top]=ele;
        return 0;
}

int pop(int *arith,int &top)
{
        int ele;
        if(top==-1)
        cout<<"stack underflow\n";
        else
        {
                ele=arith[top];
                top=top-1;
                return ele;
        }
        return -1;
}

int evaluate(char *stack,int l)
{
        int *eval = new int [30];
        int *arith = new int [30];
        int top=-1;
        getvalues(stack,eval,l);
        int elem1,elem2;
        for(int i=0;i<l;i++)
        {
                if(stack[i]=='+'||stack[i]=='-'||stack[i]=='/'||stack[i]=='*')
                {
                        if(stack[i]=='+')
                        {
                                elem1=pop(arith,top)+pop(arith,top);
                                push(elem1,arith,top);
                        }
                        else if(stack[i]=='-')
                        {
                                elem1=pop(arith,top);
                                elem2=pop(arith,top);
                                push(elem2-elem1,arith,top);
                        }
                        else if(stack[i]=='/')
                        {
                                elem1=pop(arith,top);
                                elem2=pop(arith,top);
                                push(elem2-elem1,arith,top);
                        }
                        else if(stack[i]=='*')
                        {
                                elem1=pop(arith,top)*pop(arith,top);
                                push(elem1,arith,top);
 }
                }
                else
                push(eval[i],arith,top);
        }
        cout<<"The final value\n"<<arith[0]<<endl;
        return 1;
}
int main()
{
        char *exp = new char [30];
        char *stack = new char [30];
        label:
        cout<<"Enter the infix expression\n";
        cin>>exp;
        int size=strlen(exp);
        int choice;
        cout<<"1)view postfix expression\n2)Evaluate expression\n";
        cin>>choice;
        switch(choice)
        {
                case 1: if(!viewstack(exp,stack,size))
                        goto label;
                case 2: evaluate(stack,size);
     }
        return 0;
}

