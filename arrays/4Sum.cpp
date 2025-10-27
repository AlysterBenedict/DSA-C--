#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    vector<vector<int>> results;
    int n = nums.size();

    if(n < 4)
    return results;

    for(int i = 0; i < n-3; i++)
    {
        if(i>0 && nums[i]==nums[i-1])
        continue;

        for(int j = i + 1; j < n - 2; j++)
        {
            if(j > i+1 && nums[j]==nums[j-1])
            continue;

            long long newtargetSum = (long long)target - nums[i] - nums[j];

            int left = j + 1;
            int right = n - 1;

            while(left < right)
            {

                long long currentSum = nums[left] + nums[right];
                if(currentSum == newtargetSum)
                {
                    results.push_back({nums[i], nums[j], nums[left], nums[right]});

                    left++;
                    while(left < right && nums[left] == nums[left - 1])
                    left++;

                    right++;
                    while(left < right && nums[right] == nums[right - 1])
                    right--;
                }
                

                else if(currentSum < newtargetSum)
                left++;

                else 
                right--;


            }
        }
    }
    return results;

}

// Helper function to print the result
void printResult(const vector<vector<int>>& result) {
    if (result.empty()) {
        cout << "[]" << endl;
        return;
    }
    cout << "[" << endl;
    for (const auto& quad : result) {
        cout << "  [";
        for (size_t i = 0; i < quad.size(); i++) {
            cout << quad[i] << (i == quad.size() - 1 ? "" : ", ");
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
}

int main() {
    vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    int target1 = 0;

    vector<int> nums2 = {2, 2, 2, 2, 2};
    int target2 = 8;

    vector<int> nums3 = {1000000000, 1000000000, 1000000000, 1000000000};
    int target3 = 0;

    cout << "Test Case 1:" << endl;
    printResult(fourSum(nums1, target1));
    cout << "--------------------" << endl;

    cout << "Test Case 2:" << endl;
    printResult(fourSum(nums2, target2));
    cout << "--------------------" << endl;

    cout << "Test Case 3:" << endl;
    printResult(fourSum(nums3, target3));
    cout << "--------------------" << endl;

    return 0;
}