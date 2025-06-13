#include <iostream>
#include <set>  // Required for std::set
using namespace std;

//uses tree in hood O(log n)
//same functions like map
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


cout<<"lower bound = "<<*(s.lower_bound(4))<<endl;//returns an iterator(if 4 not present give 5 ;if there is no > than 4 ,prints s.end())
cout<<"upper bound = "<<*(s.upper_bound(4))<<endl;

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


// lower_bound(key):
// Returns iterator to first element not less than key (>=)
// If key exists -> points to its first occurrence  
// If key missing -> points to smallest element greater than key  
// If no such element -> returns end()  

// upper_bound(key):  
// Returns iterator to first element greater than key (>)  
// If key exists -> points to element after last occurrence  
// If key missing -> behaves same as lower_bound  
// If no greater element -> returns end()  

// Key differences:
// - For existing keys: lower_bound=first occurrence, upper_bound=after last occurrence  
// - For missing keys: both point to same next-higher element  
// - Always use with sorted containers (set/map/vector)  

// Typical use cases:
// - lower_bound: check if key exists or find insertion point  
// - upper_bound: get range end or count duplicates  
// - Together: define range [lower_bound, upper_bound)