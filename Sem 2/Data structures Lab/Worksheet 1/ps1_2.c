#include<stdio.h>
void main()
{
        int a[100],i=0,b[3]={0};
        printf("enter the temperatures and if u want to terminate enter -1\n");
        scanf("%d",&a[0]);
        while(a[i]!=-1)
        {
                if(a[i]>84)
                b[0]++;
                else if(a[i]>59&&a[i]<85)
                b[1]++;
                else if(a[i]<60)
                b[2]++;
                i++;
                scanf("%d",&a[i]);
        }
        printf("hot days : %d\npleasant days : %d\ncold days :%d\n",b[0],b[1],b[2]);
}

