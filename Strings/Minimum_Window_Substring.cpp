#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // Edge case checks
        if (t.empty() || s.length() < t.length()) {
            return "";
        }

        // Use a vector as a frequency map for ASCII characters (faster than unordered_map)
        vector<int> t_map(128, 0);
        for (char c : t) {
            t_map[c]++;
        }

        int left = 0;                  // Left pointer of the window
        int required_matches = t.length(); // How many characters we still need to find
        int min_len = INT_MAX;         // Length of the smallest window found
        int result_start_index = 0;      // Start index of the smallest window

        // The 'right' pointer is the loop variable
        for (int right = 0; right < s.length(); right++) {
            // -- Expansion Phase --
            char char_right = s[right];

            // If the character at 'right' is part of t, it's a character we need.
            // t_map[char_right] > 0 indicates we still need more of this character.
            if (t_map[char_right] > 0) {
                required_matches--;
            }
            // Decrement the count for the character. If it wasn't in t, the count becomes negative.
            t_map[char_right]--;


            // -- Contraction Phase --
            // When required_matches is 0, we have a valid window.
            // Now, we try to shrink it from the left.
            while (required_matches == 0) {
                int current_len = right - left + 1;
                
                // Update our result if this window is smaller than the minimum found so far
                if (current_len < min_len) {
                    min_len = current_len;
                    result_start_index = left;
                }

                // Get the character at the left of the window
                char char_left = s[left];

                // As we are moving the left pointer, we are effectively "giving back"
                // the char_left to our map of needs.
                t_map[char_left]++;

                // If t_map[char_left] is now > 0, it means we have just removed a character
                // that was essential for our window. The window is no longer valid.
                if (t_map[char_left] > 0) {
                    required_matches++; // We now need to find one more character
                }
                
                // Shrink the window
                left++;
            }
        }

        // If min_len was never updated, it means no valid window was found.
        if (min_len == INT_MAX) {
            return "";
        } else {
            return s.substr(result_start_index, min_len);
        }
    }
};

int main() {
    Solution sol;

    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";
    cout << "S: \"" << s1 << "\", T: \"" << t1 << "\" -> Min Window: \"" << sol.minWindow(s1, t1) << "\"" << endl; // Expected: "BANC"

    string s2 = "a";
    string t2 = "a";
    cout << "S: \"" << s2 << "\", T: \"" << t2 << "\" -> Min Window: \"" << sol.minWindow(s2, t2) << "\"" << endl; // Expected: "a"

    string s3 = "a";
    string t3 = "aa";
    cout << "S: \"" << s3 << "\", T: \"" << t3 << "\" -> Min Window: \"" << sol.minWindow(s3, t3) << "\"" << endl; // Expected: ""

    return 0;
}