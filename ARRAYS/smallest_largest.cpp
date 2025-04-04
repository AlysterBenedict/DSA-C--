#include<iostream>
using namespace std;

int main()
{
    int min;
    int size;
    cout<<"Enter the size of the array ";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cout<<"ENter the element at pos : "<<(i+1);
        cin>>arr[i];

    }
    min=arr[0];
    for(int i=0;i<size;i++)
    {
        if(arr[i]<min)
        min=arr[i];
    }cout<<"The min element in the array is : "<<min;
}