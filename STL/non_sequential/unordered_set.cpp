#include <iostream>
#include <unordered_set>  // Changed from <set> to <unordered_set>
using namespace std;

// Uses hash table under hood O(1) average case
// Does NOT support lower_bound/upper_bound (since it's unordered)
int main() {
    unordered_set<int> s;  // Changed from set to unordered_set

    // Inserting elements (duplicates still automatically ignored)
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    // Attempting to insert duplicates (still no effect)
    s.insert(1);
    s.insert(2);
    s.insert(3);

    // Output the size (number of unique elements)
    cout << "Size: " << s.size() << endl;  // Will print 5

    // Iterating through the set (order is arbitrary)
    cout << "Elements: ";
    for(auto val : s) {
        cout << val << " ";  // Order will vary each run (e.g., "3 5 1 2 4")
    }
    cout << endl;

    return 0;
}