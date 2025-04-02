#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number n : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(n-(i+1));j++)
        {
            cout<<" ";

        }
        for(int j=0;j<(i+1);j++)
        {
            cout<<(j+1);
        }
        if(i!=0)
        {
            for(int j=i;j>=1;j--)
            {
                cout<<j;
            }
        }cout<<endl;
    }
}