#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @brief Finds all unique triplets in the array which give the sum of zero.
     * @param nums The input vector of integers.
     * @return A vector of vectors, where each inner vector is a unique triplet.
     */
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        int n = nums.size();
        
        // We need at least 3 numbers to form a triplet
        if (n < 3) {
            return results;
        }
        
        // 1. Sort the array. O(n log n)
        // This is crucial for the 2-pointer technique and duplicate skipping.
        sort(nums.begin(), nums.end());
        
        // 2. Main loop for the first element 'a'
        // We go up to n-2 because we need at least 2 elements after 'i'
        for (int i = 0; i < n - 2; i++) {
            
            // 3. Skip duplicates for the first element 'a'
            // If this element is the same as the previous one, we have already
            // processed all triplets starting with that number.
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // 4. Set up target and 2-pointers ('b' and 'c')
            // Our equation is a + b + c = 0, so b + c = -a
            int target = -nums[i];
            int left = i + 1;
            int right = n - 1;
            
            // 5. 2-pointer loop
            while (left < right) {
                int sum = nums[left] + nums[right];
                
                if (sum == target) {
                    // Found a triplet!
                    results.push_back({nums[i], nums[left], nums[right]});
                    
                    // 6. Skip inner duplicates for 'b' and 'c'
                    // Skip all identical 'b's
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    // Skip all identical 'c's
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    
                    // 7. Move pointers to the next unique elements
                    left++;
                    right--;
                    
                } else if (sum < target) {
                    // Sum is too small, need a larger number
                    left++;
                } else { // sum > target
                    // Sum is too large, need a smaller number
                    right--;
                }
            }
        }
        
        return results;
    }
};

// Main function to test the code
int main() {
    Solution sol;
    
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    cout << "Input: [-1, 0, 1, 2, -1, -4]" << endl;
    cout << "Output: " << endl;
    for (const auto& triplet : sol.threeSum(nums1)) {
        cout << "  [" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }
    // Expected: [[-1, -1, 2], [-1, 0, 1]]

    cout << "--------------------" << endl;
    
    vector<int> nums2 = {0, 0, 0, 0};
    cout << "Input: [0, 0, 0, 0]" << endl;
    cout << "Output: " << endl;
    for (const auto& triplet : sol.threeSum(nums2)) {
        cout << "  [" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }
    // Expected: [[0, 0, 0]]
    
    return 0;
}