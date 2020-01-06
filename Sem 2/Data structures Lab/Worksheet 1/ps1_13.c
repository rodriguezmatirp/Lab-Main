#include<stdio.h>
#include<string.h>
void main()
{
    int n;
    char s1[100],s2[100];
    printf("Enter the noun: ");
    scanf("%s",s1);
    n=strlen(s1);
    strcpy(s2,s1);
    if(s2[n-1]=='y')
    {
        strcpy(s2+n-1,"ies");
        n+=2;
        s2[n]='\0';
    }
    else if(s2[n-1]=='s')
    {
        strcpy(s2+n,"es");
        n+=2;
        s2[n]='\0';
    }
    else if(strcmp(s2+n-2,"sh")==0||strcmp(s2+n-2,"ch")==0)
    {
        strcpy(s2+n,"es");
        n+=2;
        s2[n]='\0';
    }
    else
    {
        s2[n]='s';
        n++;
        s2[n]='\0';
    }
    printf("The plural of the noun %s is %s\n",s1,s2);
}