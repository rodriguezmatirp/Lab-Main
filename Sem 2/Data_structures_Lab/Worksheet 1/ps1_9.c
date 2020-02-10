#include<stdio.h>
#include<string.h>
void main()
{
	char s[100];
	int n;
	printf("enter a positive number\n");
	scanf("%d",&n);
	printf("enter the text for encoding\n");
	gets(s);
	for(i=0;i<strlen(s);i++)
	s[i]+=n;
	printf("encoded text - %s\n",s);
	printf("enter the text for decoding\n");
	gets(s);
        for(i=0;i<strlen(s);i++)
        s[i]-=n;
        printf("decoded text - %s\n",s);
}
