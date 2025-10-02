//https://leetcode.com/problems/longest-common-prefix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Step 1: Handle edge case of an empty input vector.
        if (strs.empty()) {
            return "";
        }

        // Step 2: Iterate through characters of the first string.
        // This will be our reference for the prefix.
        for (int i = 0; i < strs[0].length(); i++) {
            char currentChar = strs[0][i];

            // Step 3: Compare this character with the character at the same
            // position in all other strings.
            for (int j = 1; j < strs.size(); j++) {
                // Step 4: Check for a mismatch.
                // A mismatch occurs if:
                // a) We've reached the end of the current string (strs[j]).
                // b) The characters do not match.
                if (i == strs[j].length() || strs[j][i] != currentChar) {
                    // If a mismatch is found, the common prefix is the part
                    // of the first string before the current character.
                    return strs[0].substr(0, i); //here i=number of characters from 0, not the index.
                }
            }
        }

        // Step 5: If the outer loop completes without returning,
        // it means the entire first string is the common prefix.
        return strs[0];
    }
};

// Main function to test the code
int main() {
    Solution sol;
    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << "Input: [\"flower\", \"flow\", \"flight\"]" << endl;
    cout << "Output: \"" << sol.longestCommonPrefix(strs1) << "\"" << endl; // Expected: "fl"

    cout << "---------------------" << endl;

    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << "Input: [\"dog\", \"racecar\", \"car\"]" << endl;
    cout << "Output: \"" << sol.longestCommonPrefix(strs2) << "\"" << endl; // Expected: ""

    return 0;
}