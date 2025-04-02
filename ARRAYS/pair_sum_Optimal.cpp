#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++)
    {
        cout<<"Enter the element at position "<<(i+1)<<" : ";
        cin>>arr[i];
    }
    int targetsum;
    cout<<"Enter the target sum : ";
    cin>>targetsum;
    int i=0,j=n-1;
    while(i<j)
    {
        if(arr[i]+arr[j]<targetsum)
        {
            i++;
        }else if(arr[i]+arr[j]>targetsum)
        {
            j--;
        }else if(arr[i]+arr[j]==targetsum)
        {
            cout<<i<<" , "<<j;
            return 0;
        }else
        {
            cout<<"target sum not possible with the given array !";
            return 0;
        }
        
    }
}