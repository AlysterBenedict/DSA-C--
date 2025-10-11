#include <bits/stdc++.h>
using namespace std;

class Solution  {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = n * n;
        int rep = -1;
        int missing = -1;
        vector<int> count(total + 1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int num = grid[i][j];
                count[num]++;
            }
        }

        for (int k = 1; k <= total; k++) {
            if (count[k] == 2)
                rep = k;
            if (count[k] == 0)
                missing = k;
        }

        return {rep, missing};
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{1, 3}, {2, 2}};
    vector<int> result = sol.findMissingAndRepeatedValues(grid);
    cout << "Repeated: " << result[0] << ", Missing: " << result[1] << endl; // Output: Repeated: 2, Missing: 4

    vector<vector<int>> grid2 = {{9,1,7},{8,9,2},{3,4,6}};
    vector<int> result2 = sol.findMissingAndRepeatedValues(grid2);
    cout << "Repeated: " << result2[0] << ", Missing: " << result2[1] << endl; // Output: Repeated: 9, Missing: 5
    
    return 0;
}