#include<iostream>
using namespace std;


int fact(int num)
{
    int cal=1;
    for(int i=1;i<=num;i++)
    {
        cal*=i;
    }
    return cal;
}
int binomial(int n,int r)
{
    int no,ro;
    no=fact(n);
    ro=fact(r);
    int diff;
    diff=fact(n-r);

    return (no/(ro*(diff)));
}

int main()
{
    cout<<binomial(8,2);
}