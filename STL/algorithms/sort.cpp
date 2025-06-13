#include <iostream>
#include <vector>
#include <algorithm> // Required for sort()
#include <utility>   // Required for pair
using namespace std;

int main() {
    // Example 1: Sorting a vector of integers
    vector<int> numbers = {3, 5, 1, 8, 2};

    // 1.1 Normal sorting (ascending order - default)
    sort(numbers.begin(), numbers.end());
    cout << "Ascending order (integers): ";
    for(int val : numbers) {
        cout << val << " ";
    }
    cout << endl;

    // 1.2 Descending sorting (using greater<int>())
    sort(numbers.begin(), numbers.end(), greater<int>());
    cout << "Descending order (integers): ";
    for(int val : numbers) {
        cout << val << " ";
    }
    cout << endl << endl;

    // Example 2: Sorting a vector of pairs
    vector<pair<int, int>> vec = {{3, 1}, {2, 1}, {7, 1}, {5, 2}};
    
    // 2.1 Default sorting for pairs
    // Sorts by first element, then second element (ascending)
    sort(vec.begin(), vec.end());
    cout << "Sorted pairs (ascending):" << endl;
    for(auto p : vec) {
        cout << p.first << " " << p.second << endl;
    }
    cout << endl;

    // 2.2 Custom sorting for pairs (descending first element, ascending second)
    sort(vec.begin(), vec.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });
    cout << "Custom sorted pairs (descending first, ascending second):" << endl;
    for(auto p : vec) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}