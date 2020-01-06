#include<stdio.h>

void array_in(int x,int *a,int n)
{
    int e,i;
    n=n+1;
    printf("element u want to insert\n");
    scanf("%d",&e);
    for(i=n;i>x;i--)
        a[i]=a[i-1];
    a[x]=e;
    for(i=0;i<n;i++)
        printf("%d",a[i]);
}
void insert(int *a,int n)
{
    int choice,c;
    printf("1.beginning\n2.middle\n3.end\n4.index\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:array_in(0,a,n);
                break;
        case 2:array_in(n/2,a,n);
                break;
        case 3:array_in(n-1,a,n);
                break;
        case 4:printf("the index:\n");
                scanf("%d",&c);
                array_in(c,a,n);
                break;

        default:printf("invalid");
    }
}
void array_de(int x,int *a,int n)
{
    int j;
    for(j=x;j<n;j++)
        a[j]=a[j+1];
    n=n-1;
    for(j=0;j<n;j++)
        printf("%d",a[j]);
}
void delet(int *a,int n)
{
    int choice,c;
    printf("1.beginning\n2.middle\n3.end\n4.index\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:array_de(0,a,n);
                break;
        case 2:array_de(n/2,a,n);
                break;
        case 3:array_de(n-1,a,n);
                break;
        case 4:printf("the index:\n");
                scanf("%d",&c);
                array_de(c,a,n);
                break;
        default:printf("invalid");
    }
}
int main()
{
    int i,n,choice;
    int a[100];
    printf("enter the number of elements\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("1.inserting\n2.deleting\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:insert(a,n);
                break;
        case 2:delet(a,n);
                break;
        default:printf("invalid");
    }

    return 0;
}
