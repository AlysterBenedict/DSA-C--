#include<iostream>

using namespace std;

int main()
{
    char ch;
    cout<<"Enter the character ";
    cin>>ch;

    if(ch>='a' && ch<='z')
        cout<<"the character  "<<ch<< " is a lower case";
    else
        cout<<"The character "<<ch<<" is a upper case";
}