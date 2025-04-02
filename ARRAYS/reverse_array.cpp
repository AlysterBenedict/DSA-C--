#include<iostream>
using namespace std;
int size;


void reverse(int arr[])
{
    int start=0,end=size-1;
    while(start<end)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}


int main()
{
    
    
    cout<<"Enter the size of the array : ";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cout<<"Enter the element at the pos "<<(i+1)<<" : ";
        cin>>arr[i];
    }

    reverse(arr);

    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}