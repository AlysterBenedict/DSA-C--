//https://leetcode.com/problems/reverse-words-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @brief Reverses the order of words in a string, cleaning up whitespace.
     * @param s The input string with words and spaces.
     * @return A string with words in reverse order and single spaces in between.
     */
    string reverseWords(string s) {
        string result = "";
        int n = s.length();
        int i = n - 1;

        while (i >= 0) {
            // Skip trailing spaces to find the end of a word
            while (i >= 0 && s[i] == ' ') {
                i--;
            }
            // If we've scanned past all characters, we're done
            if (i < 0) {
                break;
            }

            // At this point, i is at the last character of a word.
            // Let's find the start of this word.
            int j = i;
            while (j >= 0 && s[j] != ' ') {
                j--;
            }

            // The word is the substring from j+1 to i.
            // j is either at the space before the word or at index -1.
            // The starting index is j+1, and the length is i - (j+1) + 1 = i - j.
            string word = s.substr(j + 1, i - j);

            // Append the word to our result.
            if (!result.empty()) {
                result += " "; // Add a space before the next word
            }
            result += word;

            // Move our main pointer i to where the word search ended (at j)
            // to continue scanning for the next word to the left.
            i = j;
        }
        return result;
    }
};

int main() {
    Solution sol;
    string s1 = "the sky is blue";
    cout << "'" << s1 << "' -> '" << sol.reverseWords(s1) << "'" << endl;

    string s2 = "  hello world  ";
    cout << "'" << s2 << "' -> '" << sol.reverseWords(s2) << "'" << endl;

    string s3 = "a good   example";
    cout << "'" << s3 << "' -> '" << sol.reverseWords(s3) << "'" << endl;

    return 0;
}