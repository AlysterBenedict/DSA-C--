#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @brief Finds the container with the most water using the Two Pointer technique.
     * @param height A vector of integers representing the heights of vertical lines.
     * @return The maximum area of water that can be contained.
     */
    int maxArea(vector<int>& height) {
        // Get the number of lines
        int n = height.size();
        
        // Initialize pointers
        int left = 0;      // Pointer at the start of the array
        int right = n - 1; // Pointer at the end of the array
        
        // Variable to store the maximum area found so far
        int maxArea = 0;
        
        // Loop until the pointers cross
        while (left < right) {
            // Calculate the width of the current container
            int width = right - left;
            
            // Calculate the height of the water, limited by the shorter line
            int h = min(height[left], height[right]);
            
            // Calculate the area of the current container
            int currentArea = width * h;
            
            // Update the maximum area if the current one is larger
            maxArea = max(maxArea, currentArea);
            
            // --- The Core Logic ---
            // We need to move the pointer that points to the shorter line.
            // Why? Because moving the taller line's pointer will definitely
            // result in a smaller or equal area (width decreases, and
            // height is still limited by the same shorter line).
            // Moving the shorter line's pointer gives us a *chance* to find
            // a taller line, which *might* compensate for the decrease in width.
            if (height[left] < height[right]) {
                left++;
            } else {
                // This handles both cases:
                // 1. height[right] < height[left]
                // 2. height[right] == height[left]
                // In case 2, it doesn't matter which one we move.
                right--;
            }
        }
        
        // Return the final maximum area found
        return maxArea;
    }
};

// Main function to test the code
int main() {
    Solution sol;
    
    vector<int> h1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Input: {1, 8, 6, 2, 5, 4, 8, 3, 7}" << endl;
    cout << "Max Area: " << sol.maxArea(h1) << endl; // Expected: 49

    cout << "--------------------" << endl;

    vector<int> h2 = {1, 1};
    cout << "Input: {1, 1}" << endl;
    cout << "Max Area: " << sol.maxArea(h2) << endl; // Expected: 1
    
    return 0;
}