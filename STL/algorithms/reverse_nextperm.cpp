#include <iostream>
#include <vector>
#include <algorithm> // For reverse() and next_permutation()
using namespace std;

int main() {
    // ===== 1. reverse() =====
    vector<int> v = {1, 2, 3, 4, 5};
    
    cout << "Original vector: ";
    for(int num : v) cout << num << " ";
    cout << endl;

    // Reverse the vector
    reverse(v.begin(), v.end());
    
    cout << "After reverse(): ";
    for(int num : v) cout << num << " ";
    cout << endl << endl;

    // ===== 2. next_permutation() =====
    vector<int> perm = {1, 2, 3};
    
    cout << "All permutations of {1,2,3}:" << endl;
    do {
        for(int num : perm) cout << num << " ";
        cout << endl;
    } while(next_permutation(perm.begin(), perm.end()));

    return 0;
}