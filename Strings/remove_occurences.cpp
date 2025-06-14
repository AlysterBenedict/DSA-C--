#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOccurrences(string &s, const string &pattern) {
        size_t pos;
        while ((pos = s.find(pattern)) != string::npos) {
            s.erase(pos, pattern.length());
            // Backtrack to catch newly formed patterns
            pos = pos >= pattern.length() ? pos - pattern.length() : 0;
        }
        return s;
    }
};

int main() {
    Solution sol;
    string input_str, pattern;

    while (true) {
        cout << "Enter the string (or 'q' to quit): ";
        getline(cin, input_str);
        
        if (input_str == "q" || input_str == "Q") {
            break;
        }

        cout << "Enter the pattern to remove: ";
        getline(cin, pattern);

        string result = sol.removeOccurrences(input_str, pattern);
        cout << "Result: " << result << endl << endl;
    }

    return 0;
}