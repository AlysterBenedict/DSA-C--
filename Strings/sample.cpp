#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    long long maxSum(vector<int>& arr, int k) {
        if (k == 0) 
            return 0;

        unordered_map<int, long long> group;
        for (int num : arr) {
            if (num > 0) {
                group[num] += num;
            }
        }

        vector<long long> values;
        for (auto& kv : group) {
            values.push_back(kv.second);
        }

        if (values.empty()) {
            return 0;
        }

        sort(values.begin(), values.end(), greater<long long>());

        long long total = 0;
        int take = min(k, (int)values.size());
        for (int i = 0; i < take; i++) {
            total += values[i];
        }
        return total;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3, 2, 2, 3, 1, 1, 1};
    int k = 2;
    cout << sol.maxSum(arr, k) << endl;  // Output: 10

    arr = {5, -2, 3, 1};
    k = 2;
    cout << sol.maxSum(arr, k) << endl;  // Output: 8

    arr = {-1, -2, -3};
    k = 2;
    cout << sol.maxSum(arr, k) << endl;  // Output: 0

    return 0;
}