#include<stdio.h>
int step(int n)
{
    if(n<1)
    return 0;
    else if(n==1)
    return 1;
    else
    return step(n-1)+step(n-2);
}
int main()
{
    int n,f;
    printf("enter the number of steps\n");
    scanf("%d",&n);
    f=step(n);
    printf("the number of combinations are: %d",f);
    return 0;
}
