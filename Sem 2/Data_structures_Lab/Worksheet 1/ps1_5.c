#include<stdio.h>
void main()
{
        int n;
        printf("enter a three digit number\n");
        scanf("%d",&n);
        int a[3],i,j,num;
        a[0]=n/100;
        a[1]=(n/10)%10;
        a[2]=n%10;
        printf("the permutations are : ");
        for(i=0;i<3;i++)
        {
                num=(a[i]*100)+(a[(i+1)%3]*10)+a[(i+2)%3];
                printf("%d ",num);
        }
        for(i=0;i<3;i++)
        {
                num=(a[i]*100)+(a[(i+2)%3]*10)+a[(i+1)%3];
                printf("%d ",num);
        }

}
