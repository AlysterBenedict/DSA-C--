#include<iostream>
using namespace std;
int main()
{
    int i, n,divisible=0;
    bool prime=true;
    cout<<"Enter the number : ";
    cin>>n;
    if(n<=1)
    {
        cout<<n<<" is not a prime number ";
        
    }
    else
    {
        for(i=2;i<=n-1;i++)
        {
            if(n%i==0)
            {
                
                cout<<n<<" is divisible by "<<i<<endl;
                prime=false;
                divisible+=1;
            }
            else
            {
                prime=true;
            }
        }
    if(divisible==0)
    cout<<n<<" is a prime number";
    else
    cout<<"\n"<<"Hence "<<n<<" is not a prime number";

}
}

