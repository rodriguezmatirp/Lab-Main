#include<stdio.h>
int main()
{
    int n,sum=0,a[1000],i;
    printf("enter the number of elements\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(i=0;i<n+1;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n+1;i++)
    {
        sum+=a[i];
    }
    sum=sum-((n)*(n+1)/2);

    printf("the missing number : %d\n",-sum);
    return 0;
}
