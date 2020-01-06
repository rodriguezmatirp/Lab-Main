#include<iostream>
using namespace std;

void total(int *a,int n)
{
    int i,sum=0;
    for(i=0;i<n;i++)
        sum+=a[i];
    cout<<"Sum : "<<sum<<endl;
    cout<<"Average : %f"<<sum/n<<end;
}
int grethan(int *a,int n)
{
    cout<<"Enter a specific number\n";
    int i,num,j=0;
    cin>>num;
    for(i=0,i<n;i++)
    {
        if(a[i]>num)
        j++;
        else
        continue;
    }
    return j;
}
void present(int *a,int n)
{
    int num,i;
    cout<<"Enter a number to check\n";
    cin>>num;
    for(i=0;i<n;i++)
    {
        if(a[i]==num)
        {
            cout<<"number is present\n";
            j=1;
            break;
        }
        else
        continue;
    }
    if(j!=1)
        cout<<"Number is not present\n";
}
void countpn(int *a,int n)
{
    int i,p=0,n=0;
    for(i=0;i<n;i++)
    {
        if(a[i]>0)
        p++;
        else if(a[i]<0)
        n++;
        else
        continue;
    }
    cout<<"Positive Numbers:"<<p<<endl;
    cout<<"Negative Numbers:"<<n<<endl;
}
void countoe(int *a,int n)
{
    int i,b[100],c[100];
    int j=0,k=0;
    for(i=0;i<n;i++)
    {
        if(a[i]%2==0)
        {
            b[j]=a[i];
            j++;
        }
        else if(a[i]%2!=0)
        {
            c[k]=a[i];
            k++;
        }
    }
    cout<<"Even elements\n";
    for(i=0;i<j;i++)
        cout<<b[i]<<endl;
    cout<<"Odd elements\n";
    for(i=0;i<k;i++)
        cout<<c[i]<<endl;
}
void replace(int *a.int n)
{
    int i,num;
    cout<<"Enter a element to replace\n";
    cin>>num;
    for(i=0;i<n;i=i+2)
        a[i]=num;
    for(i=0;i<n;i++)
        cout<<a[i]<<endl;
}
void search(int *a,int n)
{
    int i,num,j=0;
    cout<<"Enter a element to search\n";
    cin>>num;
    for(i=0;i<n;i++)
    {
        if(a[i]==num)
            j+=i;
        else
        continue;
    }
    if(j=0)
    cout<<"Element not found\n";
    else
    {
        cout<<"Element is found\n";;
        cout<<"Sum of indexes:"<<j<<endl;
    }
}
int main()
{
    int a[100],n,i;
    cout<<"Enter the number of elements\n";
    cin>>n;
    cout<<"Enter the elements\n";
    for(i=0;i<n;i++)
        cin>>a[i];
    total(a,n);
    cout<<"Number of elements greater than the specific number :"<< grethan(a,n)<<endl;
    present(a,n);
    countpn(a,n);
    countoe(a,n);
    replace(a,n);
    search(a,n);
    return 0;

}
