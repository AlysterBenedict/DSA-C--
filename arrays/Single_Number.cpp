#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a=0;
        for(int num : nums)
        {
            a=a^num;
        }
        return a;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "The single number is: " << sol.singleNumber(nums) << endl; 
    return 0;
}