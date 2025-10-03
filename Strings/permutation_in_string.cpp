#include<bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2)
{
    int m=s1.length();
    int n=s2.length();

    //frequency array
    vector<int> s1map(26,0);
    vector<int> s2map(26,0);
 //Edge case: impossible for s2 to contain a permutation of s1.
    if(m>n)
    return false;

   //populate the sliding windows of s1 and s2
    for(int i=0;i<m;i++)
    {
        s1map[s1[i]- 'a']++;
        s2map[s2[i]- 'a']++;
    }
// check if the first slide is a match
    if(s1map==s2map)
    return true;

    //slide the window by one pos at each iteration and compare
    for(int j=m;j<n;j++)
    {
        s2map[s2[j]- 'a']++;
        s2map[s2[j-m]- 'a']--;
        if(s1map==s2map)
    return true;
    }
    return false;  //no match found
}

int main()
{
    string s1,s2;
    cout<<"Enter s1: ";
    getline(cin,s1);
    cout<<"Enter s2: ";
    getline(cin,s2);
    if(checkInclusion(s1, s2))
    cout<<"Permutation found !";
    else
    cout<<"Permutation not found ";
}