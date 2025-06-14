#include <iostream>
#include <string>
using namespace std;

void remove(string &s, const string &pattern) {
    size_t pos = s.find(pattern); 
    while (pos != string::npos) {
        s.erase(pos, pattern.length()); 
        pos = s.find(pattern, pos); 
    }
}

int main() {
    string s = "abbbaaacccbbbacbabcabcaabbccabc";
    string pattern ="abc";
    remove(s, pattern);
    cout << s << endl;
    return 0;
}
