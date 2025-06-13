#include <iostream>
#include <vector>
#include <algorithm> // Required for sort() function
#include <utility>   // Required for pair container
using namespace std;

int main() {
    // Initialize a vector of integer pairs
    vector<pair<int, int>> vec = {{3, 1}, {2, 1}, {7, 1}, {5, 2}};

    // Sort the vector using a custom comparator
    // The third parameter to sort() is a lambda function that defines our sorting rules
    sort(vec.begin(), vec.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        // Primary sorting condition: compare first elements of pairs
        // If first elements are equal (a.first == b.first)
        if(a.first == b.first) {
            // Secondary sorting condition: sort by second element in ascending order
            // Return true if a's second element should come before b's
            return a.second < b.second;
        }
        // Default case: sort by first element in descending order
        // Return true if a's first element should come before b's
        return a.first > b.first;
    });

    // Output the sorted pairs
    cout << "Sorted pairs (descending first, ascending second):" << endl;
    for(auto p : vec) {
        // Print each pair's first and second elements
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}