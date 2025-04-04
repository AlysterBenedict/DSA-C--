#include<iostream>

using namespace std;

int dectobin(int num)
{

    int sum=0;
    int pow=1;
    int rem;
    while(num>0)
    {
        rem=num%2;
        num=num/2;
        sum+=rem*pow;
        pow*=10;
    }return sum;
}

int bintodec(int bin)
{
    int rem;
    int sum1=0;
    int pow=1;
    while(bin>0){

    rem=bin%10;
    bin/=10;
    sum1+=rem*pow;
    
    pow*=2;
    }
    return sum1;
}
int main()
{
    int num,bin;
    cout<<" Enter the number for decimal to binary conversion : ";
    cin>>num;

    cout<<"The binary equivalent of "<<num<<" is = "<<dectobin(num);

    cout<<endl;
    cout<<"Enter the binary number : ";
    cin>>bin;
    cout<<"The decimal equivalent of "<<bin<<" is = "<<bintodec(bin);
}
