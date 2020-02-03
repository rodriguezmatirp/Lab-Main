#include<bits/stdc++.h>
using namespace std;

class donor
{
    static int o,ul,sul;
    int number;
    string name;
    int age;
    char sex;
    string bloodgroup;
    public:
    int blood_donor(string );
    int blood_donor(int ,int );
    int blood_donor(char ,string ,int ,int );
};

int donor::o=0;
int donor::ul=0;
int donor::sul=0;

void donor :: blood_donor(string blood_grp)
{
    if(blood_grp==bloodgroup)
    o++;
} 

void donor :: blood_donor(int upper,int lower)
{
    if(age>=lower&&age<=upper)
    ul++;
}

void donor ::blood_donor(char sex1,string blood_grp,int upper,int lower)
{
    if(age<=upper&&age>=lower&&blood_grp==bloodgroup&&sex1==sex)
    sul++;
}
