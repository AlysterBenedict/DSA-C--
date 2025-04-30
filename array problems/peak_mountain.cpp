#include<iostream>
#include<vector>
using namespace std;

int peak(vector<int> &arr)
{
int n= arr.size();
int st=1;
int end=n-2;
int mid;
while(st<=end)
{
    mid=st+(end-st)/2;
    if(arr[mid]>arr[mid-1]&& arr[mid]>arr[mid+1])
    return mid;
    else if(arr[mid]>arr[mid-1])
    st=mid+1;
    else
    end=mid-1;

}
}

int main()
{
    vector<int> arr;
    cout<<"Enter the size of the array: ";
    int n;
    cin>>n;
    int i=0;
    cout<<"ENter the elements of the array : ";
    while(i<n)
    {
        int x;
        cin>>x;
        arr.push_back(x);
        i++;
    }
    int ans=peak(arr);
    cout<<"The peak element is at index : "<<ans<<endl;
    cout<<"The peak element is : "<<arr[ans]<<endl;
}