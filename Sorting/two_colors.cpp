#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n,n0=0,n1=0,n2=0;
    
    cout<<"Enter the size of the vector : ";
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

    for(int i=0;i<n;i++)
    {
        if (nums[i]==0)
        n0++;
        else if(nums[i]==1)
        n1++;
        else 
        n2++;
    }

    int i=0;
    for(;i<n0;i++)
    {
        nums[i]=0;
    }
    for(;i<n1+n0;i++)
    {nums[i]=1;
    }
    for(;i<n2+n0+n1;i++)
    {nums[i]=2;
    }

    cout<<"The sorted Array is :";
    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<" ";
    }
}