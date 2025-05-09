#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int> &arr, int N,int C,int mindist)
{
    int cows=1;
    int lastStall=arr[0];
    for(int i=0;i<N;i++)
    {
        if(arr[i]-lastStall >=mindist)
        {
            cows++;
            lastStall=arr[i];

        }
        if(cows==C)
        return true;
    }return false;
}

int getDistance(vector<int> &arr, int N ,int C)
{
    sort(arr.begin(), arr.end());
    int st=1 , end=arr[N-1] - arr[0];int ans;

    while(st<=end)
    {
        int mid=st+(end-st)/2;
       if(isPossible(arr,N,C,mid))
       {
        //move right
        ans=mid;
        st=mid+1;

       }else{
        end=mid-1;

       }
    }return ans;
}

int main()
{
    int n,C;
    cout<<"Enter the number of cows : ";
    cin>>C;
    cout<<"Enter the number of stalls: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the distance between each of the stalls :";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

    }
    int ans = getDistance(arr,n,C);
    cout<<"the minimum number of maximum pages which can be aloocated to a student is : " <<ans<<endl;
    return 0;
}