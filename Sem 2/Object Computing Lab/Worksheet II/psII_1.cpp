#include<iostream>
#include<cstdio>
#include<ios>
#include<limits>
using namespace std;

class country
{
    public:
    string name;
    long int population;
    double area;
    void get_inputs();
};

void country::get_inputs()
{
    cout<<"Enter the name of the country"<<endl;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin,name);
    cout<<"Enter the population of country"<<endl;
    cin>>population;
    cout<<"Enter the area of the country"<<endl;
    cin>>area;
}

void largest_population(country c[],int size)
{
    int i,max=c[0].population,k=0;
    for(i=0;i<size;i++)
    {
        if(c[i].population>max)
        {
            max=c[i].population;
            k=i;
        }
        else
        continue;
    }
    cout<<"The largest popululation : "<<c[k].name<<"  with  "<<c[k].population<<endl;
}

void largest_area(country c[],int size)
{
    int i,k=0;
    double max=c[0].area;
    for(i=0;i<size;i++)
    {
        if(c[i].area>max)
        {
            max=c[i].area;
            k=i;
        }
        else
        continue;
    }
    cout<<"The largest area : "<<c[k].name<<"  with  "<<c[k].area<<endl;
}

void largest_populationDensity(country c[],int size)
{
    double max=c[0].population/c[0].area;
    int i,k=0;
    for(i=0;i<size;i++)
    {
        if( (c[i].population/c[i].area) > max)
        {
            max=c[i].population/c[i].area;
            k=i;
        }
        else
        continue;
    }
    cout<<"The largest population density : "<<c[k].name<<"  with  "<<c[k].population/c[k].area<<endl;
}

int main()
{
    int size,i;
    cout<<"Enter the number if countries"<<endl;
    cin>>size;
    country c[10];
    for(i=0;i<size;i++)
    {
        cout<<"country  "<<i+1<<endl;
        c[i].get_inputs();
    }
    largest_population(c,size);
    largest_area(c,size);
    largest_populationDensity(c,size);

    return 0;
}
