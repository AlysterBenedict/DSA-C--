#include <bits/stdc++.h>
using namespace std;

/**
 * @class Solution
 * Solves the "Merge Intervals" problem (LeetCode 56).
 * The strategy is to sort the intervals by their start time
 * and then iterate through, merging any overlapping intervals.
 */
class Solution {
public:
    /**
     * @brief Merges overlapping intervals in a given list.
     * @param intervals A vector of intervals, where each interval is [start, end].
     * @return A new vector of merged, non-overlapping intervals.
     */
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        // --- Step 1: Handle Edge Case ---
        // If the input list is empty, return an empty list.
        if (intervals.empty()) {
            return {};
        }

        // --- Step 2: Sort the Intervals ---
        // We sort the intervals based on their start time (intervals[i][0]).
        // This is the most crucial step, as it allows us to perform
        // the merge in a single O(N) pass.
        sort(intervals.begin(), intervals.end());

        // --- Step 3: Initialize Result Vector ---
        // Create a 'merged' vector to store our final non-overlapping intervals.
        vector<vector<int>> merged;
        
        // Add the very first interval (which is now the one with the
        // smallest start time) to our 'merged' list to begin.
        merged.push_back(intervals[0]);

        // --- Step 4: Iterate and Merge ---
        // Loop from the second interval (index 1) to the end.
        for (int i = 1; i < intervals.size(); i++) {
            
            // --- Reference vs. Copy ---
            
            // Get a reference (&) to the current interval from the input list.
            // We use '&' for PERFORMANCE. It avoids making an unnecessary
            // copy of the vector [start, end] in every loop iteration.
            // We are only reading from 'current', so 'const&' would be even better practice.
            vector<int>& current = intervals[i];
            
            // Get a reference (&) to the last interval added to our 'merged' list.
            // We use '&' for CORRECTNESS. We need to *modify* this interval
            // in-place if it overlaps with 'current'. If we didn't use '&',
            // 'last' would be a *copy*, and our changes wouldn't
            // affect the interval inside the 'merged' vector.
            vector<int>& last = merged.back();
            
            // --- Step 5: Check for Overlap ---
            // An overlap occurs if the current interval's start time
            // is less than or equal to the last merged interval's end time.
            if (current[0] <= last[1]) {
                // --- Merge Logic ---
                // An overlap is found! We merge them.
                
                // We need to find the new end time for the 'last' interval.
                // It will be the maximum of its current end and the 'current' interval's end.
                // This handles cases like [1,10], [2,5] (contained) and [1,5], [3,8] (partial).
                int val = max(current[1], last[1]);
                
                // Because 'last' is a REFERENCE, this line directly modifies
                // the interval inside the 'merged' vector.
                last[1] = val;
            } 
            else {
                // --- No Overlap ---
                // The 'current' interval starts *after* the 'last' one ends.
                // This means 'current' is a new, non-overlapping interval.
                // Add it to our 'merged' list.
                merged.push_back(current);
            }
        }
        
        // --- Step 6: Return Result ---
        return merged;
    }
};

/**
 * @brief Helper function to print a vector of intervals.
 * @param intervals The vector of [start, end] pairs to print.
 */
void printIntervals(const vector<vector<int>>& intervals) {
    cout << "[";
    for (int i = 0; i < intervals.size(); i++) {
        cout << "[" << intervals[i][0] << "," << intervals[i][1] << "]";
        if (i < intervals.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

/**
 * @brief Main function to demonstrate the Solution class.
 */
int main() {
    // Create an instance of our Solution class
    Solution sol;

    // --- Example 1: Standard Overlaps ---
    vector<vector<int>> intervals1 = {{1,3}, {2,6}, {8,10}, {15,18}};
    cout << "Test Case 1" << endl;
    cout << "Input:  ";
    printIntervals(intervals1);
    
    vector<vector<int>> result1 = sol.merge(intervals1);
    
    cout << "Output: ";
    printIntervals(result1); // Expected: [[1,6], [8,10], [15,18]]
    cout << "--------------------" << endl;

    // --- Example 2: Touching Intervals ---
    vector<vector<int>> intervals2 = {{1,4}, {4,5}};
    cout << "Test Case 2" << endl;
    cout << "Input:  ";
    printIntervals(intervals2);
    
    vector<vector<int>> result2 = sol.merge(intervals2);
    
    cout << "Output: ";
    printIntervals(result2); // Expected: [[1,5]]
    cout << "--------------------" << endl;

    // --- Example 3: Contained Interval ---
    vector<vector<int>> intervals3 = {{1,10}, {2,6}, {3,7}};
    cout << "Test Case 3" << endl;
    cout << "Input:  ";
    printIntervals(intervals3);
    
    vector<vector<int>> result3 = sol.merge(intervals3);
    
    cout << "Output: ";
    printIntervals(result3); // Expected: [[1,10]]
    cout << "--------------------" << endl;

    // --- Example 4: Unsorted Input ---
    vector<vector<int>> intervals4 = {{8,10}, {15,18}, {1,3}, {2,6}};
    cout << "Test Case 4 (Unsorted)" << endl;
    cout << "Input:  ";
    printIntervals(intervals4);
    
    vector<vector<int>> result4 = sol.merge(intervals4);
    
    cout << "Output: ";
    printIntervals(result4); // Expected: [[1,6], [8,10], [15,18]]
    cout << "--------------------" << endl;

    return 0;
}