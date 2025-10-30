#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @brief Finds the next lexicographically greater permutation of numbers.
     * * @param nums A vector of integers to be modified in-place.
     */
    void nextPermutation(vector<int>& nums) {
        // Get the size of the array
        int n = nums.size();
        
        // Base case: If 0 or 1 element, no permutation is possible.
        if (n <= 1) {
            return;
        }

        // Step 1: Find the pivot 'k'
        // Iterate from second-to-last element down to the first.
        int k = -1;
        for (int i = n - 2; i >= 0; i--) {
            // Find the first element that is smaller than the element to its right.
            if (nums[i] < nums[i + 1]) {
                k = i;
                break; // Found the pivot, stop.
            }
        }

        // Step 2: If no pivot is found (k == -1), the array is sorted in descending order.
        // This is the largest permutation.
        if (k == -1) {
            // The "next" permutation is the smallest one (sorted ascending).
            // We can get this by reversing the entire array.
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find the successor 'l' to swap with the pivot 'k'
        // Find the smallest element in the suffix [k+1, n-1] that is > nums[k].
        int l = -1;
        for (int i = n - 1; i > k; i--) {
            if (nums[i] > nums[k]) {
                l = i;
                break; // Found the successor, stop.
            }
        }

        // Step 4: Swap the pivot (nums[k]) and the successor (nums[l])
        swap(nums[k], nums[l]);

        // Step 5: Reverse the suffix from k+1 to the end
        // This makes the suffix as small as possible (ascending order).
        reverse(nums.begin() + k + 1, nums.end());
    }
};

// Helper function to print the vector
void printVector(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1, 2, 3};
    cout << "Original: "; printVector(nums1);
    sol.nextPermutation(nums1);
    cout << "Next:     "; printVector(nums1); // Output: 1 3 2

    cout << "---" << endl;

    // Example 2
    vector<int> nums2 = {3, 2, 1};
    cout << "Original: "; printVector(nums2);
    sol.nextPermutation(nums2);
    cout << "Next:     "; printVector(nums2); // Output: 1 2 3

    cout << "---" << endl;

    // Example 3
    vector<int> nums3 = {1, 1, 5};
    cout << "Original: "; printVector(nums3);
    sol.nextPermutation(nums3);
    cout << "Next:     "; printVector(nums3); // Output: 1 5 1
    
    cout << "---" << endl;
    
    // Example 4 (Complex)
    vector<int> nums4 = {1, 5, 8, 4, 7, 6, 5, 3, 1};
    cout << "Original: "; printVector(nums4);
    sol.nextPermutation(nums4);
    cout << "Next:     "; printVector(nums4); // Output: 1 5 8 5 1 3 4 6 7

    return 0;
}