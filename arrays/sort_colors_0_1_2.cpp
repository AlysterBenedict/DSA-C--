#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @brief Sorts an array of 0s, 1s, and 2s in-place using the
     * Dutch National Flag (3-pointer) algorithm.
     * @param nums The vector of integers to be sorted.
     */
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        // Initialize three pointers:
        // 'low' points to the next slot for a 0
        // 'mid' points to the current element being inspected
        // 'high' points to the next slot for a 2
        int low = 0;
        int mid = 0;
        int high = n - 1;

        // Loop as long as 'mid' has not passed 'high'
        // The region [mid...high] is the "unknown" partition
        while (mid <= high) {
            
            switch (nums[mid]) {
                
                case 0:
                    // We found a 0.
                    // Swap it with the element at 'low'.
                    swap(nums[low], nums[mid]);
                    
                    // Both 'low' and 'mid' pointers move one step forward.
                    // 'low' moves because we've placed a 0 correctly.
                    // 'mid' moves because the element swapped from 'low'
                    // is guaranteed to be either 0 or 1, which is
                    // already processed.
                    low++;
                    mid++;
                    break;
                    
                case 1:
                    // We found a 1.
                    // It's in the correct place (the middle partition).
                    // Just move 'mid' to inspect the next element.
                    mid++;
                    break;
                    
                case 2:
                    // We found a 2.
                    // Swap it with the element at 'high'.
                    swap(nums[mid], nums[high]);
                    
                    // Decrement 'high' because we've placed a 2 correctly.
                    //
                    // !!! IMPORTANT !!!
                    // We DO NOT increment 'mid'. The new element at nums[mid]
                    // (which just came from nums[high]) is "unknown"
                    // and must be processed in the next loop iteration.
                    high--;
                    break;
            }
        }
    }
};

// Helper function to print a vector
void printVector(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function to test the code
int main() {
    Solution sol;
    
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    cout << "Original 1: ";
    printVector(nums1);
    sol.sortColors(nums1);
    cout << "Sorted 1:   ";
    printVector(nums1); // Expected: 0 0 1 1 2 2

    cout << "--------------------" << endl;

    vector<int> nums2 = {2, 0, 1};
    cout << "Original 2: ";
    printVector(nums2);
    sol.sortColors(nums2);
    cout << "Sorted 2:   ";
    printVector(nums2); // Expected: 0 1 2

    return 0;
}