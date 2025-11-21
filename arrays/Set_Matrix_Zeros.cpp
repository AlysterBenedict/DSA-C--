#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();      // Number of rows
        int m = matrix[0].size();   // Number of columns
        
        // Flag to check if the 0-th column needs to be set to 0
        // We can't store this in matrix[0][0] because that cell is reserved for the 0-th ROW.
        int col0 = 1; 

        // STEP 1: Traverse the matrix and mark the first row & first col
        for (int i = 0; i < n; i++) {
            // Check if the cell in the 0-th column is 0
            if (matrix[i][0] == 0) {
                col0 = 0;
            }
            
            // Traverse the rest of the row (starting from index 1)
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0; // Mark the row header
                    matrix[0][j] = 0; // Mark the col header
                }
            }
        }

        // STEP 2: Traverse from bottom-up and right-to-left to fill zeroes
        // We go backwards to ensure we don't taint the reference headers (row 0/col 0) too early
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 1; j--) {
                // Check headers: if row header OR col header is 0
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            // Finally check the separate flag for the 0-th column
            if (col0 == 0) {
                matrix[i][0] = 0;
            }
        }
    }
};

// Helper function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> matrix1 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    cout << "Original Matrix 1:" << endl;
    printMatrix(matrix1);
    sol.setZeroes(matrix1);
    cout << "Modified Matrix 1:" << endl;
    printMatrix(matrix1);
    // Expected Output:
    // 1 0 1 
    // 0 0 0 
    // 1 0 1 

    // Test Case 2
    vector<vector<int>> matrix2 = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };
    cout << "Original Matrix 2:" << endl;
    printMatrix(matrix2);
    sol.setZeroes(matrix2);
    cout << "Modified Matrix 2:" << endl;
    printMatrix(matrix2);
    // Expected Output:
    // 0 0 0 0 
    // 0 4 5 0 
    // 0 3 1 0 

    // Test Case 3 (Single row/column with zero)
    vector<vector<int>> matrix3 = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };
    cout << "Original Matrix 3:" << endl;
    printMatrix(matrix3);
    sol.setZeroes(matrix3);
    cout << "Modified Matrix 3:" << endl;
    printMatrix(matrix3);
    // Expected Output:
}