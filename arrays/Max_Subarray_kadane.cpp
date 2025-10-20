#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds the maximum sum of a contiguous subarray using Kadane's Algorithm.
 * @param nums A vector of integers.
 * @return The maximum subarray sum.
 */
int maxSubArray(vector<int>& nums) {
    // Problem constraints say nums.length >= 1, so nums[0] is safe to access.
    
    // current_sum tracks the maximum sum of a subarray ENDING at the current index.
    int current_sum = nums[0];
    
    // global_max tracks the maximum sum found ANYWHERE in the array so far.
    int global_max = nums[0];
    int start,end=0;
    // Iterate from the second element (index 1)
    for (int i = 1; i < nums.size(); i++) {
        
        // The core logic of Kadane's Algorithm:
        // Is it better to start a new subarray at nums[i]?
        // Or is it better to extend the previous best subarray by adding nums[i]?
        current_sum = max(nums[i], current_sum + nums[i]);
        start=i;
        // Update the overall global maximum if the current subarray's sum is larger.
        global_max = max(global_max, current_sum);

        end=i;
    }
    
    // After checking all elements, global_max holds the answer.
    return global_max;
}

int main() {
    // Example 1
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Input: [-2, 1, -3, 4, -1, 2, 1, -5, 4]" << endl;
    cout << "Max Sum: " << maxSubArray(nums1) << endl; // Output: 6

    cout << "--------------------" << endl;

    // Example 2 (All negatives)
    vector<int> nums2 = {-5, -1, -3};
    cout << "Input: [-5, -1, -3]" << endl;
    cout << "Max Sum: " << maxSubArray(nums2) << endl; // Output: -1
    
    cout << "--------------------" << endl;
    
    // Example 3 (All positives)
    vector<int> nums3 = {1, 2, 3, 4, 5};
    cout << "Input: [1, 2, 3, 4, 5]" << endl;
    cout << "Max Sum: " << maxSubArray(nums3) << endl; // Output: 15

    return 0;
}