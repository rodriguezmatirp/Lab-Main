#include<stdio.h>
void main()
{
	float sum[4]={0},total=0;
	int A[4][5],i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			scanf("%d",&A[i][j]);
			sum[i]=sum[i]+A[i][j];
			total=total+A[i][j];
		}
	}
	for(i=0;i<4;i++)
	{
		printf("candidate %d :: \nvote percentage  : %f total vote : %f\n",i+1,(sum[i]/total)*100,sum[i]);
	}
	int max=sum[0],k;
	for(i=0;i<4;i++)
	{
		if(max<sum[i])
		max=sum[i];
		k=i;
	}
	printf("the winner is candidate %d with vote percentage %f\n",k+1,(max/total));
}
