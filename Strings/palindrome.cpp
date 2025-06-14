#include<string.h>
#include<iostream>
using namespace std;

bool isPalindrome(string str)
{
    auto st=str.begin();
    auto end=str.end()-1;
    while (st<=end)
    {
        if(*st==*end)
        {
        bool var=true;
        end--;st++;}
        else
        return 0;

    }
    return true;

}
int main()
{
    string str;
    cout<<"Enter a string : ";
    cin>>str;

    if(isPalindrome(str))
    cout<<"\nThe string "<<str<<" is a palindrome!";
    else
    cout<<"\nThe string "<<str<<" is not a palindrome!";
}

