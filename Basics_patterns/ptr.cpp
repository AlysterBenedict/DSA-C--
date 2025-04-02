#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the value : ";
    cin>>n;

    int *ptr=&n;

    cout<<ptr<<endl;
    
    cout<<&n<<endl;

    cout<<*ptr;
}