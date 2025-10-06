#include<bits/stdc++.h>
using namespace std;

string minWindow( string s ,string t)
{
    int left=0;
    int minlength=INT_MAX;
    int remaining=t.length();
    int result_start_index=0;

    if(t.empty() || s.length() < t.length())
    return "";

    vector<int> tmap(128,0);
    for ( char ch : t)
    {
        tmap[ch]++;

    }



    for(int right=0; right<s.length(); right++)
    {
        char char_right= s[right];
        //Expand
        if(tmap[char_right] > 0)
        remaining--;

        tmap[char_right]--;

        //Contraction
        while(remaining==0)
        {
            int current_length=right-left+1;

            if(current_length<minlength)
            {
                minlength=current_length;
                result_start_index=left;
            }
            char char_left=s[left];
            tmap[char_left]++;

            if(tmap[char_left] >0)
            remaining++;

            left++;
        }
    }

    if(minlength==INT_MAX)
    return "";
    else
    return s.substr(result_start_index,minlength);
}


int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    string result = minWindow(s, t);
    cout << "Minimum window substring: " << result << endl;

    return 0;
}