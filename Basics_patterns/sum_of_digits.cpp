#include<iostream>
using namespace std;


int digitSum(int num)
{
    int sum=0;
    int lastdigit;
    while(num>0){
    lastdigit=num%10;
    sum+=lastdigit;
    num=num/10;}
return sum;

}
int main()
{
    cout<<digitSum(123);
}