#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @brief Searches for a target value in an m x n matrix with sorted properties.
     * @param matrix The 2D vector (matrix) of integers.
     * @param target The integer value to search for.
     * @return true if the target is found, false otherwise.
     */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Get dimensions
        int m = matrix.size(); // Number of rows
        if (m == 0) return false;
        
        int n = matrix[0].size(); // Number of columns
        if (n == 0) return false;

        // Treat the m x n matrix as a flattened 1D array of size (m * n)
        // We will binary search on the indices from 0 to (m*n - 1)
        int low = 0;
        int high = (m * n) - 1;

        while (low <= high) {
            // Calculate the middle index (1D)
            // Using (low + (high - low) / 2) to prevent potential integer overflow
            int mid_index = low + (high - low) / 2;

            // Convert the 1D 'mid_index' back to 2D (row, col) coordinates
            // row = index / num_cols
            // col = index % num_cols
            int row = mid_index / n;
            int col = mid_index % n;

            int mid_value = matrix[row][col];

            if (mid_value == target) {
                // Found the target
                return true;
            } else if (mid_value < target) {
                // The target must be in the "right" half of the virtual array
                low = mid_index + 1;
            } else {
                // mid_value > target
                // The target must be in the "left" half of the virtual array
                high = mid_index - 1;
            }
        }

        // If the loop finishes, the target was not found
        return false;
    }
};

// --- Example Main Function (for testing) ---
int main() {
    Solution sol;

    vector<vector<int>> matrix1 = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target1 = 3;
    cout << "Searching for 3: " << (sol.searchMatrix(matrix1, target1) ? "true" : "false") << endl; // Output: true

    int target2 = 13;
    cout << "Searching for 13: " << (sol.searchMatrix(matrix1, target2) ? "true" : "false") << endl; // Output: false

    vector<vector<int>> matrix2 = {{1}};
    int target3 = 1;
    cout << "Searching for 1: " << (sol.searchMatrix(matrix2, target3) ? "true" : "false") << endl; // Output: true

    return 0;
}