#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int p = -1;
        for (int i = (int)nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                p = i;
                break;
            }
        }
        
        // for not pivot element(decreasing order array)
        if (p == -1) {
            sort(nums.begin(), nums.end());
            return;
        }
        
        //smallest larger element right to p in the given nums array(if nums[p]=2 find a num that is >2 but less that the rest
        int q = p + 1;
        for (int j = q; j < nums.size(); j++) {
            if (nums[j] > nums[p]) {
                q = j;
            }
        }
        swap(nums[p], nums[q]);
        
        //sort to get the next permutation
        sort(nums.begin() + p + 1, nums.end());
    }
};

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    Solution sol;
    sol.nextPermutation(nums);
    
    cout << "Next permutation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
