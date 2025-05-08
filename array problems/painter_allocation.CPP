#include<iostream>
#include<vector>
#include <climits>
using namespace std;

bool isValid(vector<int> &arr, int n, int m,int maxTime)
{
    int time=0,painter=1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>maxTime)
        {
            return false;
        }
        if(time+arr[i]<=maxTime)
        {
            time+=arr[i];

        }else
        {
            painter++;
            time=arr[i];
        }
    }return painter<=m? true : false;
}


int minpainter(vector<int> &arr, int n, int m)
{
    int maxValue=INT_MIN;
    int start=0;
    int end=0;int sum=0;

    //range
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        maxValue=max(maxValue,arr[i]);
    }

    start=maxValue;
    end=sum;
int mid;
int ans=-1;
    //binary search
    while(start<=end)
    {
         mid=start+(end-start)/2;
        if(isValid(arr, n, m,mid))
        {
             ans=mid;
            end=mid-1;

        }else{
            start=mid+1;

        }
    }return ans;
}

int main()
{
    int n,m;
    cout<<"Enter the number of blocks : ";
    cin>>n;
    cout<<"Enter the number of painters : ";
    cin>>m;
    vector<int> arr(n);
    cout<<"Enter the time of each block :";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

    }
    int ans = minpainter(arr,n,m);
    cout<<"the minimum time required by the painter is : " <<ans<<endl;
    return 0;
}