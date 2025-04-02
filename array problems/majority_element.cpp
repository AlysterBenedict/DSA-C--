#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> arr={2,2,2,3,4,2,3,4,2,3,3,3,3,3,3,3,3,3};
    int n=arr.size();
    int count=0;
    int currele;
    for(int i=0;i<n;i++)
    {
        currele=arr[i];
        count=0;
        for(int j=0;j<n;j++)
        {
            if (currele==arr[j])
            {
                count++;
            }
            
        }
        if (count>n/2)
            {
                cout<<currele<<endl;
                break;
            }
    }
}