#include<iostream>
using namespace std;

int main()
{
    int n,sum=0;
    cout<<"Enter the number : ";
    cin>>n;
    for (int i=0;i<=n;i++)
    {
        if(i%2!=0)
        sum+=i;
    }
    cout<<sum;

}