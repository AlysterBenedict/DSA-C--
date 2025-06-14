#include<iostream>
#include <string.h>
using namespace std;

int main()
{
    char str[]="Alyster Benedict";
    cout<<str;
    cout<<endl;
    cout<<str[2]<<endl;

    char strin[100];
    cin>>strin;  //cin ignores the space btw the words
    cout<<strin;
    cout<<"\nString length : "<<strlen(strin)<<endl;

    char strin2[100];
    cin.getline(strin2,100); //includes space sytax : cin.getline(str,size,delimiter(stop character like . , $ etc...))
    int len=0; 
    for(int i=0;i<strin2[i]!='\0';i++)
    {
        len++;
    }
    cout<<"\nOutput"<<strin2;

    
}