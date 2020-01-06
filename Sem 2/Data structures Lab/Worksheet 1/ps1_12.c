#include<stdio.h>
#include<string.h>
void main()
{
  char s[100],s1[100],s2[30]={0};
  printf("Enter the word_1\n");
  scanf("[%^\n]s",s);
  printf("Enter the word_2\n");
  scanf("[%^\n]s",s1);
  int n=strlen(s),i;
  for(i=0;i<n;i++)
  {
    if(s[i]==s1[i])
    s2[i]=s[i];
  }
  s2[i]='\0';
  if(s2[0]==0)
  printf("Empty string\n");
  else
  printf("The common prefix : %s",s2);
}
