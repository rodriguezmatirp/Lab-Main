#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<time.h>
struct bill
{
    int pen;
    int pencil;
    int paper;
    int notebook;
    int eraser,sharpner;
    int total;
}b;
void help()
{
    printf("CODE NUMBER\tITEM\tPRICE(in rupees)\n");
    printf("101\tPENCIL\t15\n");
    printf("201\tPEN\t30\n");
    printf("301\tPAPER\t2\n");
    printf("401\tNOTEBOOK\t50\n");
    printf("501\tSHARPNER\t5\n");
    printf("601\tERASER\t5\n");
}
int count(int code)
{
    int price;
    if(code==101)
    {
        printf("Enter the quantity of pencils\n");
        scanf("%d",&b.pencil);
        printf("PENCILS : %d\t",b.pencil);
        price=b.pencil*15;
        return price;
    }
    else if(code==201)
    {
        printf("Enter the quantity of pens\n");
        scanf("%d",&b.pen);
        printf("PEN : %d\t",b.pen);
        price=b.pen*30;
        return price;
    }
    else if(code==301)
    {
        printf("Enter the quantity of papers\n");
        scanf("%d",&b.paper);
        printf("PAPERS : %d\t",b.paper);
        price=b.paper*2;
        return price;
    }
    else if(code==401)
    {
        printf("Enter the quantity of notebooks\n");
        scanf("%d",&b.notebook);
        printf("NOTEBOOKS : %d\t",b.notebook);
        price=b.notebook*50;
        return price;
    }
    else if(code==501)
    {
        printf("Enter the quantity of sharpners\n");
        scanf("%d",&b.sharpner);
        printf("SHARPNERS : %d\t",b.sharpner);
        price=b.sharpner*5;
        return price;
    }
    else if(code==601)
    {
        printf("Enter the quantity of erasers\n");
        scanf("%d",&b.eraser);
        printf("ERASERS : %d\t",b.eraser);
        price=b.eraser*5;
        return price;
    }
    else 
    {
        printf("invalid code\nTRY AGAIN\n");
        billing();
    }

}
void storefile(int code,int price,FILE *fp)
{
    if(code==101)
    fprintf(fp,"%d\tPENCIL\t",code);
    else if(code==201)
    fprintf(fp,"%d\tPEN\t",code);
    else if(code==301)
    fprintf(fp,"%d\tPAPER\t",code);
    else if(code==401)
    fprintf(fp,"%d\tNOTEBOOK\t",code);
    else if(code==501)
    fprintf(fp,"%d\tSHARPNER\t",code);
    else if(code==601)
    fprintf(fp,"%d\tERASER\t",code);
    fprintf(fp,"%d\n",price);   
}
int billing()
{
    char bill;
    int code;
    int price;
    printf("Enter Y to start billing or N to stop billing");
    scanf("%c",&bill);
    if(bill=='N'||bill=='n')
    return 0;
    else
    {
        FILE *fp;
        fp=fopen("BILLRECORDS.txt","a");
        if(fp==NULL)
        printf("could not able to open the file\n");
        else
        {
            time_t t;
            time(&t);
            fprintf(fp,"-------------------------------------------------------------------\nSTATIONARY BILLING\n");
            fprintf(fp,"\n\t%s\n\n",ctime(&t));
            while(bill=='y'||bill=='Y')
            {
                printf("Enter the code\n");
                scanf("%d",&code);
                price=count(code);
                b.total+=price;
                printf("price : %d\n",price);
                storefile(code,price,fp);
            }
            fprintf(fp,"TOTAL BILL : %d\n-----------------------------------------------------------------",b.total);
            fclose(fp);
            return 1;
        }
    }
    
}
int main()
{
    int choice,success;
    int b.total=0;
    printf("1.HELP\n2.BILLING\n");
    if(choice==1)
    help();
    else if(choice==2)
    success=billing();
    else
    exit();
    
    if(success==1)
    printf("billing successful\n");
    else
    printf("billing unsuccessful\n");
}