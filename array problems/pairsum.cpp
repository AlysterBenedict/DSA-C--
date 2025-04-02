#include<iostream>
#include<vector>
using namespace std;
//o(n) time complexity and o(1) space complexity
//using two pointer approach
//given sorted array and target sum
//find the pair of elements whose sum is equal to target
int main()
{
    int target=12;
    vector<int> arr={2,4,6,8,10};
    int n=arr.size();
    int sum=0;
    int *start=&arr[0];
    int *end=&arr[n-1];
    while(start<end)
    {
        sum=*start+*end;
        if (sum==target)
        {
            cout<<(start - &arr[0])<<" , "<<(end - &arr[0])<<endl;
            break;
        }
        else if (sum<target)
        {
            start++;
        }
        else
        {
            end--;
        }
    }


}