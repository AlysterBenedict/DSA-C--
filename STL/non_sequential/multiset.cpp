#include <iostream>
#include <set>  // multiset is in the same header as set
using namespace std;

// Uses tree in hood O(log n)
// Allows duplicate elements
int main() {
    multiset<int> ms;  // Creates an empty multiset of integers

    // Inserting elements (duplicates are allowed)
    ms.insert(1);
    ms.insert(2);
    ms.insert(3);
    ms.insert(4);
    ms.insert(5);

    // Inserting duplicates (will be added)
    ms.insert(1);
    ms.insert(2);
    ms.insert(3);

    // lower_bound and upper_bound work differently with duplicates
    cout << "lower bound of 3 = " << *ms.lower_bound(3) << endl; // First 3
    cout << "upper bound of 3 = " << *ms.upper_bound(3) << endl; // First element > 3

    // Output the size (counts all elements, including duplicates)
    cout << "Size: " << ms.size() << endl;  // Will print 8 (5 + 3 duplicates)

    // Iterating through the multiset (elements are automatically sorted)
    cout << "Elements: ";
    for(auto val : ms) {
        cout << val << " ";  // Will print "1 1 2 2 3 3 4 5"
    }
    cout << endl;

    // Count occurrences of a value
    cout << "Count of 3: " << ms.count(3) << endl;  // Will print 2

    return 0;
}