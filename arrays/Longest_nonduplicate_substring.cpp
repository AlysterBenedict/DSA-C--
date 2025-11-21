#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, maxLen = 0;
        vector<int> notebook(256, -1); // Stores the last seen index of each character

        while (right < s.length()) {
            int curr = s[right];
            
            // If the current character has been seen before in the current window
            if (notebook[curr] != -1 && notebook[curr] >= left) {
                // Move the left pointer to the position right after the last occurrence
                left = notebook[curr] + 1;
            }
            
            // Update the last seen index of the current character
            notebook[curr] = right;
            
            // Update the maximum length found so far
            maxLen = max(maxLen, right - left + 1);
            
            // Expand the window
            right++;
        }
        return maxLen;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    string s1 = "abcabcbb";
    cout << "Input: \"" << s1 << "\"" << endl;
    cout << "Length of Longest Substring: " << sol.lengthOfLongestSubstring(s1) << endl; // Expected: 3 ("abc")

    cout << "--------------------" << endl;

    // Test Case 2
    string s2 = "bbbbb";
    cout << "Input: \"" << s2 << "\"" << endl;
    cout << "Length of Longest Substring: " << sol.lengthOfLongestSubstring(s2) << endl; // Expected: 1 ("b")

    cout << "--------------------" << endl;

    // Test Case 3
    string s3 = "pwwkew";
    cout << "Input: \"" << s3 << "\"" << endl;
    cout << "Length of Longest Substring: " << sol.lengthOfLongestSubstring(s3) << endl; // Expected: 3 ("wke")

    cout << "--------------------" << endl;

    // Test Case 4
    string s4 = "";
    cout << "Input: \"" << s4 << "\"" << endl;
    cout << "Length of Longest Substring: " << sol.lengthOfLongestSubstring(s4) << endl; // Expected: 0

    cout << "--------------------" << endl;

    // Test Case 5
    string s5 = "dvdf";
    cout << "Input: \"" << s5 << "\"" << endl;
    cout << "Length of Longest Substring: " << sol.lengthOfLongestSubstring(s5) << endl; // Expected: 3 ("vdf")

    return 0;
}

