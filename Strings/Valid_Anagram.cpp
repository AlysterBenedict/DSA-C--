#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{
    if(s.length() != t.length())
    return false;

    vector<int> counts(26,0);
    
    for(int i=0;i<s.length();i++)
    {
        counts[s[i]-'a']++;
    }

    for(int j=0;j<t.length();j++)
    {
        counts[t[j]-'a']--;
        
        if(counts[t[j]-'a'] < 0)
        return false;
    }return true;


}
int main() {
    
    string s1 = "anagram";
    string t1 = "nagaram";
    cout << "s = \"" << s1 << "\", t = \"" << t1 << "\": " << (isAnagram(s1, t1) ? "true" : "false") << endl;

    string s2 = "rat";
    string t2 = "car";
    cout << "s = \"" << s2 << "\", t = \"" << t2 << "\": " << (isAnagram(s2, t2) ? "true" : "false") << endl;
    return 0;
}