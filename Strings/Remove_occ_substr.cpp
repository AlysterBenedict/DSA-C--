#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @brief Repeatedly removes the leftmost occurrence of a substring.
     * @param s The main string to modify.
     * @param part The substring to remove.
     * @return The string 's' after all removals.
     */
    string removeOccurrences(string s, string part) {
        // Continue looping as long as we can find 'part' within 's'.
        // s.find(part) returns string::npos if the substring is not found.
        while (s.find(part) != string::npos) {
            // Find the starting index of the leftmost occurrence of 'part'.
            size_t index = s.find(part);
            
            // Erase the substring 'part' from 's'.
            // The erase function takes the starting position and the number of characters to remove.
            s.erase(index, part.length());
        }
        
        return s;
    }
};

int main() {
    Solution sol;
    string s1 = "daabcbaabcbc";
    string part1 = "abc";
    cout << "s = \"" << s1 << "\", part = \"" << part1 << "\" -> \"" << sol.removeOccurrences(s1, part1) << "\"" << endl;

    string s2 = "axxxxyyyyb";
    string part2 = "xy";
    cout << "s = \"" << s2 << "\", part = \"" << part2 << "\" -> \"" << sol.removeOccurrences(s2, part2) << "\"" << endl;
    
    return 0;
}