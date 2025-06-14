#include <iostream>
#include <string>  // Use <string> instead of <string.h>
using namespace std;

int main() {
    // Declare all variables at the top to avoid redeclaration
    string str = "Alyster Benedict";
    string str2 = "ster";
    string str3;  // Only declare once

    // Get input for str3 first to avoid confusion
    cout << "Enter a string: ";
    getline(cin, str3);
    cout << "You entered: " << str3 << endl;

    // Demonstrate string operations
    cout << "Original str: " << str << endl;
    
    str = "Aly";  // String reassignment
    cout << "Modified str: " << str << endl;
    
    cout << "Concatenation: " << str + str2 << endl;  // concatenation
    cout << "Comparison (==): " << (str == str2) << endl; // comparison
    cout << "Comparison (>): " << (str > str2) << endl; // lexicographical comparison

    // Get another input
    cout << "Enter another string: ";
    getline(cin, str3);
    cout << "You entered: " <<endl;

    for(int i=0 ; i<str3.length();i++)
    {
        cout<<str3[i];
    }


    return 0;
}