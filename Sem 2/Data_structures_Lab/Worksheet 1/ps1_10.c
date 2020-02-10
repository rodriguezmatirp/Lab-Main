#include<stdio.h>
#include<string.h>
void main()
{
	char s[80];
	printf("enter the text\n");
	gets(s);
	printf("enter the text to be searched\n");
	char t[10];
	int i,j=0,k=0;
	gets(t);
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]==t[j])
		j++;
		else
		j=0;
		if(j==strlen(t))
		{
			printf("the text to be replaced\n");
                	char r[10];
                	gets(r);
                	for(k=0;k<strlen(t);k++)
                	s[k+i-strlen(t)+1]=r[k];
			break;
		}
	}
	if(j!=strlen(t))
	printf("search failed\n");
	printf("the final text is : %s\n",s);
}
