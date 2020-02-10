#include<stdio.h>
void main()
{
        printf("enter the number of elements in array A and B\n");
        scanf("%d %d",&n1,&n2);
        int a1[n1],a2[n2],a3[100];
        int i,sum=0;
        printf("enter the elements in A");
        for(i=0;i<n1;i++)
        {
                scanf("%d",&a1[i]);
                sum=sum+a1[i];
        }
        printf("sum of A :%d\n",sum);
        sum=0;
        printf("enter the elements in B");
        for(i=0;i<n2;i++)
        {
                scanf("%d",&a2[i]);
                sum=sum+a2[i];
        }
        printf("sum of B :%d\n",sum);
}
