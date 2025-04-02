#include<iostream>
#include<vector>
using namespace std;
int main()

{
    vector<int>ans;
    int sum;
    int arr[]={1,5,9,7,8};
    cout<<"Enter the target sum : ";
    cin>>sum;
    int size=(sizeof(arr))/(sizeof(int));
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]+arr[j]==sum)
            {
                ans.push_back(i);
                ans.push_back(j);
            }
        }
    }

if(ans.size()==0)
{
    cout<<"No pair sum";
}else{


cout<<"The pair sum is : "<<endl;
for(int value : ans)
{
    cout<<value<<" ";
}
} 
}