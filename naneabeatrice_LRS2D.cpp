#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("input.dat");

int n;
int info[100], st[100], dr[100];

struct Nod
{
    int nr;
    int info;
    int* st;
    int* dr;
};
Nod dat[100];

int read_data()
{
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>info[i];
    }
    for(int i=1;i<=n;i++)
    {
        fin>>st[i];
    }
    for(int i=1;i<=n;i++)
    {
        fin>>dr[i];
    }
}

int conversie()
{
    for(int i=1;i<=n;i++)
    {
        dat[i].nr=i;
        dat[i].info=info[i];
        dat[i].st=&st[i];
        dat[i].dr=&dr[i];
    }

}

int arboreRSD(int k)
{
    cout<<dat[k].info<<" ";
    if(*dat[k].st!=0)
    {
        arboreRSD(*dat[k].st);
    }
    if(*dat[k].dr!=0)
    {
        arboreRSD(*dat[k].dr);
    }
}

int arboreSRD(int k)
{
    if(*dat[k].st!=0)
    {
        arboreSRD(*dat[k].st);
    }
    cout<<dat[k].info<<" ";
    if(*dat[k].dr!=0)
    {
        arboreSRD(*dat[k].dr);
    }
}

int arboreSDR(int k)
{
    if(*dat[k].st!=0)
    {
        arboreSDR(*dat[k].st);
    }
    if(*dat[k].dr!=0)
    {
        arboreSDR(*dat[k].dr);
    }
    cout<<dat[k].info<<" ";
}

int main()
{
    read_data();
    conversie();
    arboreRSD(1);
    cout<<endl;
    arboreSRD(1);
    cout<<endl;
    arboreSDR(1);
}
