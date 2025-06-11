#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Resize nums1 to fit both arrays
        nums1.resize(m + n);
        
        // Initialize pointers for the end of each array
        int i = m - 1; // Pointer for nums1 (end of actual elements)
        int j = n - 1; // Pointer for nums2 (end of elements)
        int k = m + n - 1; // Pointer for the end of the merged array in nums1
        
        // Merge from the end to avoid overwriting elements in nums1
        while(i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        
        // If there are remaining elements in nums2, copy them
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums1, nums2;
    int m, n, val;

    // Input for nums1
    cout << "Enter size of nums1 (m): ";
    cin >> m;
    cout << "Enter " << m << " elements for nums1 (sorted): ";
    for(int i = 0; i < m; i++) {
        cin >> val;
        nums1.push_back(val);
    }

    // Input for nums2
    cout << "Enter size of nums2 (n): ";
    cin >> n;
    cout << "Enter " << n << " elements for nums2 (sorted): ";
    for(int i = 0; i < n; i++) {
        cin >> val;
        nums2.push_back(val);
    }

    // Merge the arrays
    sol.merge(nums1, m, nums2, n);

    // Output the result
    cout << "Merged array: ";
    for(int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
