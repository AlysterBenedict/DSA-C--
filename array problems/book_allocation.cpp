#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int> &arr,int n,int m, int maxpg)
{
    int student=1,pgs=0;

    //edge case
    for(int i=0;i<n;i++)
    {
        if(arr[i]>maxpg)
        return false;

        if (pgs+arr[i]<=maxpg)
        pgs+=arr[i];
        else
        {
            student++;
            pgs=arr[i];

        }
    }return student> m? false: true;
}


int allocateBooks(vector<int> &arr,int n, int m)
{
    if(m>n)
    return -1;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    int start=0;
    int end=sum; //range of possible answers to apply binary search
    int ans=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        
        if(isValid(arr,n,m,mid))
        {
            end=mid-1;//go left
            ans=mid;
        }else
        {start=mid+1; //move right}
    }


}return ans;
}

int main()
{
    int n,m;
    cout<<"Enter the number of books : ";
    cin>>n;
    cout<<"Enter the number of students : ";
    cin>>m;
    vector<int> arr(n);
    cout<<"Enter the number of pages in each book :";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

    }
    int ans = allocateBooks(arr,n,m);
    cout<<"the minimum number of maximum pages which can be aloocated to a student is : " <<ans<<endl;
    return 0;
}