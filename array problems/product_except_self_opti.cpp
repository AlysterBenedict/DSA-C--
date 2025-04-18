#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
           int n=nums.size();
           vector<int> result(n, 1);
    
           for(int i = 1; i < n; ++i) {
               result[i] = result[i - 1] * nums[i - 1];
           }
           int suffix = 1;
           for(int i = n - 2; i >= 0; --i) {
               suffix*=nums[i+1];
               result[i]*=suffix;
           }
          
        return result;
        } 
    };
int main()
{
    int n;
    cout<<"Enter the number of elements in the array : ";
    cin>>n;
    cout<<"Enter the elements of the array : ";
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    Solution sol;
    
    vector<int> products = sol.productExceptSelf(nums);
    
    cout << "The product of all elements except the current element is: ";
    for (int num : products) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}