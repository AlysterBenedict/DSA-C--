#include <iostream>
#include <string> // For std::string (recommended) and cin.ignore()
#include <limits> // For numeric_limits
#include <string.h> // For strlen()

using namespace std;

int main() {
    // ---- Part 1: Reading a single word with cin ----
    char strin[100];
    cout << "Enter a full name : ";
    cin >> strin; 

    cout << "Output from cin >>: " << strin << endl;
    cout << "Length using strlen: " << strlen(strin) << endl;

    // ---- Part 2: Fixing the input buffer ----
    // cin >> left " lastname\n" in the input buffer.
    // We must clear it before using cin.getline().
    // cin.ignore() will discard the rest of the line until it sees a newline.
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // ---- Part 3: Reading a full line with cin.getline() ----
    char strin2[100];
    cout << "\nNow, enter a full sentence: ";
    cin.getline(strin2, 100); // Used only for char arrays

    cout << "Output from cin.getline: " << strin2 << endl;
    
    // ---- Part 4: Manual length calculation (Corrected loop) ----
    int len = 0;
    for (int i = 0; strin2[i] != '\0'; i++) {
        len++;
    }
    cout << "Manual length calculation: " << len << endl;

    return 0;
}