//https://leetcode.com/problems/valid-palindrome/description/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(string s)
{
    int left=0;
    int right=s.length()-1;

    while(left<right)
    {
        while(left<right && !isalnum(s[left]))
        left++;

        while(left<right && !isalnum(s[right]))
        right--;

        if(tolower(s[left]) != tolower(s[right]))
        return false;

        left++;
        right--;
        
    }return true;


}
int main() {
    
    string s1 = "A man, a plan, a canal: Panama";
    cout << "'" << s1 << "' is a palindrome: " << boolalpha <<isPalindrome(s1) << endl;

    string s2 = "race a car";
    cout << "'" << s2 << "' is a palindrome: " << boolalpha <<isPalindrome(s2) << endl;

    string s3 = "";
    cout << "'" << s3 << "' is a palindrome: " << boolalpha <<isPalindrome(s3) << endl;
    
    return 0;
}
