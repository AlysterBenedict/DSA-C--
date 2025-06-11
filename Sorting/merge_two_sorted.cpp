#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m);
        
        for(int j = 0; j < n; j++) {
            bool inserted = false;
            
            for(int i = 0; i < (int)nums1.size() - 1; i++) {
                if(nums2[j] >= nums1[i] && nums2[j] <= nums1[i+1]) {
                    nums1.insert(nums1.begin() + (i+1), nums2[j]);
                    inserted = true;
                    break;
                }
            }
            
            if(!inserted) {
                if(nums1.empty() || nums2[j] >= nums1.back()) {
                    nums1.push_back(nums2[j]);
                }
                else {
                    nums1.insert(nums1.begin(), nums2[j]);
                }
            }
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

    // Add extra space for merging
    cout << "Enter size of nums2 (n): ";
    cin >> n;


    // Input for nums2
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