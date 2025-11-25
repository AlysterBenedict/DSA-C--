#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/product-of-array-except-self/description/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        // Initialize answer array with size n, filled with 1s.
        // This array will serve as our output and temporary storage for prefix products.
        vector<int> ans(n, 1);

        // ---------------------------------------------------------
        // PASS 1: Calculate Prefix Products (Left to Right)
        // ---------------------------------------------------------
        // ans[i] should contain the product of all elements to the left of i
        // We start from i = 1 because there are no elements to the left of index 0.
        for(int i = 1; i < n; i++) {
            ans[i] = ans[i-1] * nums[i-1];
        }

        // ---------------------------------------------------------
        // PASS 2: Calculate Suffix Products (Right to Left)
        // ---------------------------------------------------------
        // We maintain a running variable 'suffix' to store the product 
        // of all elements to the right of current index i.
        int suffix = 1;
        
        for(int i = n - 1; i >= 0; i--) {
            // Multiply the already stored prefix product with the current suffix product
            ans[i] = ans[i] * suffix;
            
            // Update the suffix product for the next iteration (moving left)
            suffix = suffix * nums[i];
        }

        return ans;
    }
};

// Driver Code for testing
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = sol.productExceptSelf(nums);
    
    cout << "Output: [";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << (i < result.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;
    
    return 0;
}