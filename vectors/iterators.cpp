#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};

    // 1. Forward iteration using explicit iterator
    cout << "Forward iteration (using iterator): ";
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // 2. Reverse iteration using reverse_iterator
    cout << "Reverse iteration (using reverse_iterator): ";
    for(vector<int>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); rit++) {
        cout << *rit << " ";
    }
    cout << endl;

    // 3. Forward iteration using auto
    cout << "Forward iteration (using auto): ";
    for(auto it = vec.begin(); it != vec.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // 4. Reverse iteration using auto
    cout << "Reverse iteration (using auto): ";
    for(auto rit = vec.rbegin(); rit != vec.rend(); rit++) {
        cout << *rit << " ";
    }
    cout << endl;

    // 5. Range-based for loop (modern C++ approach)
    cout << "Range-based for loop: ";
    for(int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}