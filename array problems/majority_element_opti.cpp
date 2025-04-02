#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> arr = {2, 2, 2, 3, 4, 2, 3, 4, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2};
    int n = arr.size();
    int count = 1; // Start count at 1 for the first element
    int currele = arr[0]; // Assume the first element is the majority candidate

    // Sort the array
    sort(arr.begin(), arr.end());

    // Iterate through the sorted array
    for (int i = 1; i < n; i++) {
        if (arr[i] == currele) {
            count++; // Increment count if the current element matches
            if (count > n / 2) {
                cout << "Majority element: " << currele << endl;
                return 0; // Exit the program if the majority element is found
            }
        } else {
            // Reset count for the new element
            currele = arr[i];
            count = 1;
        }
    }

    // If no majority element is found
    cout << "No majority element exists." << endl;
    return 0;
}