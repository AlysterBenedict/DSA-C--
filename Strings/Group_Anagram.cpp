#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    unordered_map<string,vector<string>> anagram_map;

    for(const string & s: strs)
    {
        vector<int> counts(26,0);
        for(char c : s)
        {
            counts[c-'a']++;
        }

        string key="";
        for(int count : counts)
        {
            
            key+="#" + to_string(count);
        }
        anagram_map[key].push_back(s);
    }

    vector<vector<string>> result;
    for(auto const& [key,val] : anagram_map)
    {
        result.push_back(val);
    }
return result;
}

int main() {

    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

 
    vector<vector<string>> result = groupAnagrams(strs);

  
    cout << "Input: [\"eat\", \"tea\", \"tan\", \"ate\", \"nat\", \"bat\"]" << endl;
    cout << "Grouped Anagrams Output:" << endl;
    cout << "[" << endl;
    for (const auto& group : result) {
        cout << "  [ ";
        for (const string& s : group) {
            cout << "\"" << s << "\" ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;

    return 0;
}