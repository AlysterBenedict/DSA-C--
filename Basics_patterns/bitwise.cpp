#include <iostream>
using namespace std;

int main()
{
    int a = 8, b = 4; // Declaration of variables for demonstration

    // Demonstration of Left Shift (Multiplication equivalent)
    cout << "Left Shift (Multiplication): ";
    cout << (a << 3); // Equivalent to a * 8
    cout << endl;

    // Demonstration of Right Shift (Division equivalent)
    cout << "Right Shift (Division): ";
    cout << (b >> 2); // Equivalent to b / 4
    cout << endl;

    // Example of Using Both Operations Together
    cout << "Example Using Both Operations: ";
    int result = a << 3; // Multiply by 8
    result = result >> 2; // Divide by 4
    cout << result << endl;

    // Standard Size Output
    cout << "Size of int: " << sizeof(int) << endl;
    return 0;
}