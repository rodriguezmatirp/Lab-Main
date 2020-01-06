#include<stdio.h>
#include<string.h>

void main()
{
	int n;char name[3][10];int b[3][5];int sum[3]={0};int tot[5]={0};int i,j;
	printf("enter no. of employee\n");
	scanf("%d",&n);
	printf("Enter name and production outputs\n");
	for(i=0;i<n;i++)
	{
		gets(name[i]);
		for(j=0;j<5;j++)
		{
			scanf("%d",&b[i][j]);
			sum[i]=sum[i]+b[i][j];
		}
	}
	for(i=0;i<5;i++)
		for(j=0;j<n;j++)
			tot[i]=tot[i]+b[i][j];
	printf("Emp Name\tMon\tTue\tWed\tThu\tFri\tTotals\n");
	for(i=0;i<n;i++)
	{
		printf("%s",name[i]);
		for(j=0;j<5;j++)
			printf("%d\t",b[i][j]);
		printf("%d\n",sum[i]);
	}
	printf("totals\t");
	for(i=0;i<5;i++)
	printf("%d\t",tot[i]);
}
