#include<iostream>
using namespace std;
int main()
{
    //factorial of a number n
    int g,facto=1;
    cout<<"Enter the number : ";
    cin>>g;
    for(int i=g;i>=1;i--)
    {
        facto=facto*i;
    }

    cout<<"The factorial of "<<g<<" is : "<<facto;
}