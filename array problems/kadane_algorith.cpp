#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n, maxsum,cursum;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    maxsum=INT_MIN; // Initialize max to the smallest possible integer value
cursum=0;

    for(int i=0;i<n;i++)
    {
        cursum+=arr[i];
        maxsum=max(cursum,maxsum);
        if(cursum<0)
        cursum=0;
    }
    cout<<"The max sum using kadane's algorithm is : "<<maxsum<<endl;
}
