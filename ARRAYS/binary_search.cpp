#include<iostream>

using namespace std;
int main()
{
    int n;
    int start=0;
    
    int mid=0;  //mid always takes the lower value of the two middle values
    // in case of even number of elements in the array.
    // For example, if the array is of size 6, mid will be 2 and not 3.
    int key;
    
    cout<<"Enter the size of the array : ";
    cin>>n;
    int arr[n];
    int end=n-1;
    cout<<"Enter the elements of the array : ";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"Enter the element to be searched : ";
    cin>>key;

    while(start<=end)
    {
        mid=(start+(end-start))/2;   //int max addition can cause overflow, so we use this formula to calculate mid.
        //mid=(start+end)/2;  //This can cause overflow if start and end are large.
        if(arr[mid]==key)
        {
            cout<<"Index of "<<key<<" is : " <<mid<<endl;
            break;
        }
        else if(arr[mid]<key)
        start=mid+1;
        else
        end=mid-1;
    }
}