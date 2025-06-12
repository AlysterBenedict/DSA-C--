#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // Remove elements at positions 1 (value 2) through 3 (value 4)
    auto first = vec.begin() + 1; // Get iterator to element 2
    auto last = vec.begin() + 3;  // Get iterator to element 5 (one past the end of range)
    vec.erase(first, last);      // Erase elements from 2 to 4

    for (int i : vec) {
        std::cout << i << " "; // Output: 1 5
    }
    return 0;
}
