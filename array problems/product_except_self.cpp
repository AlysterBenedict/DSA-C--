#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int n=nums.size();
       vector<int> prefix(n, 1), suffix(n, 1), result(n, 1);

       for(int i = 1; i < n; ++i) {
           prefix[i] = prefix[i - 1] * nums[i - 1];
       }
       for(int i = n - 2; i >= 0; --i) {
           suffix[i] = suffix[i + 1] * nums[i + 1];
       }
       for(int i = 0; i < n; ++i) {
        result[i] = prefix[i] * suffix[i];
    }
    return result;
    } 
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> products = sol.productExceptSelf(nums);
    
    cout << "The product of all elements except the current element is: ";
    for (int num : products) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}