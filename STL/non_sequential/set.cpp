#include <iostream>
#include <set>  // Required for std::set
using namespace std;

int main() {
    set<int> s;  // Creates an empty set of integers

    // Inserting elements (duplicates are automatically ignored)
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    // Attempting to insert duplicates (will have no effect)
    s.insert(1);
    s.insert(2);
    s.insert(3);

    // Output the size (number of unique elements)
    cout << "Size: " << s.size() << endl;  // Will print 5

    // Iterating through the set (elements are automatically sorted)
    cout << "Elements: ";
    for(auto val : s) {
        cout << val << " ";  // Will print "1 2 3 4 5"
    }
    cout << endl;

    return 0;
}