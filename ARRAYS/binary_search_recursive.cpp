#include<iostream>
using namespace std;

int binarysearch(int arr[], int start, int end, int key)
{
    if(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]<key)
            return binarysearch(arr,mid+1,end,key);

        else if(arr[mid]>key)
            return binarysearch(arr,start,mid-1,key);

        else
            return mid;
    }   
    return -1;
}

int main()
{
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array : ";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int key;
    cout<<"Enter the element to be searched : ";
    cin>>key;
    
    int index=binarysearch(arr,0,n-1,key);
    
    if(index==-1)
    cout<<key<<"\n not found in the array."<<endl;
    else
    cout<<"\nIndex of "<<key<<" is : " <<index<<endl;
}