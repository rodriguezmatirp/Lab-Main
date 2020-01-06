#include<stdio.h>
void main()
{
        int n;
        printf("enter the number of elements in the list\n");
        scanf("%d",&n);
        int a[n],i,sum=0;
        float avg;
        printf("enter the elements\n");
        for(i=0;i<n;i++)
        {
                scanf("%d",&a[i]);
                sum=sum+a[i];
        }
        avg=sum/n;
        printf("the average is : %f\n",avg);
        float standev=0;
        for(i=0;i<n;i++)
        {
                standev=standev+(avg-a[i])*(avg-a[i]);
        }
        standev=standev/n;
        printf("the standard deviation of the following list is : %f\n",standev);
        int num;
        printf("enter the number for checking\n");
        scanf("%d",&num);
        int j=0;
        for(i=0;i<n;i++)
        {
                if(num<=a[i])
                j++;
        }
        printf("the no. of integers which are greater than or equal to the number given is :%d\n",j);

}
