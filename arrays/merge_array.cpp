#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Merges two sorted arrays in-place using the two-pointer approach.
 * @param nums1 The first array, which has space to hold the merged result.
 * @param m The number of initialized elements in nums1.
 * @param nums2 The second array.
 * @param n The number of initialized elements in nums2.
 */
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // Pointer for the last element of the initial part of nums1
    int p1 = m - 1;
    // Pointer for the last element of nums2
    int p2 = n - 1;
    // Pointer for the last position in the merged nums1 array
    int p_merged = m + n - 1;

    // Iterate backwards from the end of nums2
    while (p2 >= 0) {
        // If p1 is valid and the element in nums1 is larger than in nums2
        if (p1 >= 0 && nums1[p1] > nums2[p2]) {
            // Place the larger element (from nums1) at the end of nums1
            nums1[p_merged] = nums1[p1];
            p1--; // Move the nums1 pointer to the left
        } else {
            // Place the element from nums2 (it's either larger or p1 is out of bounds)
            nums1[p_merged] = nums2[p2];
            p2--; // Move the nums2 pointer to the left
        }
        // Move the insertion pointer to the left
        p_merged--;
    }
}

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    merge(nums1, m, nums2, n);

    cout << "Merged Array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl; // Expected Output: 1 2 2 3 5 6

    return 0;
}
