#include<stdio.h>
void main()
{
        char a[10]={'b','c','a','d','a','b','c','d','a','c'};
        char b[10];
        int i,sum=0;
        printf("please enter ur answers\nenter 'u' if unanswered\n");
        for(i=0;i<10;i++)
        {
                scanf("%c",&b[i]);
                if(b[i]==a[i])
                sum=sum+4;
                else if(b[i]=='u')
                sum+=0;
                else if(b[i]!=a[i])
                sum=sum-1;
        }
        printf("ur score is : %d\n",sum);
}




