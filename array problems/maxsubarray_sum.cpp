#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int n,maxsum,cursum;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    maxsum=INT_MIN; // Initialize max to the smallest possible integer value
    

    for(int start=0;start<n;start++)
    {
        cursum=0; //reset  cursum value

        for(int end=start;end<n;end++)
        {
            cursum+=arr[end];
        }
        maxsum=max(maxsum,cursum);
    }

    cout<<"The maximum sum of the subarray is : "<<maxsum<<endl;
}