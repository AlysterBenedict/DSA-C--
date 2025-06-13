#include <iostream>
#include <algorithm>  // For swap, min, max
#include <vector>
using namespace std;

int main() {
    // ===== 1. swap() =====
    int a = 5, b = 10;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    swap(a, b);  // Swaps the values
    cout << "After swap: a = " << a << ", b = " << b << endl << endl;

    // ===== 2. min() and max() =====
    int x = 7, y = 4;
    cout << "Numbers: " << x << " and " << y << endl;
    cout << "Min: " << min(x, y) << endl;  // Returns the smaller value
    cout << "Max: " << max(x, y) << endl << endl;  // Returns the larger value

    // ===== Multiple values comparison =====
    cout << "Min of 5, 3, 8: " << min({5, 3, 8}) << endl;  // Initializer list version
    cout << "Max of 5, 3, 8: " << max({5, 3, 8}) << endl << endl;

    // ===== With custom comparator =====
    auto abs_compare = [](int a, int b) { return abs(a) < abs(b); };
    cout << "Min absolute (-5 vs 3): " << min(-5, 3, abs_compare) << endl;
    cout << "Max absolute (-5 vs 3): " << max(-5, 3, abs_compare) << endl;

    return 0;
}