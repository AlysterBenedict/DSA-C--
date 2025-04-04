#include <iostream>
#include <vector>
#include <algorithm> // For sort function
using namespace std;

int binary(const vector<int>& vec, int target) {
    int i = 0;
    int j = vec.size() - 1;

    while (i <= j) {
        int mid = (i + j) / 2; // Calculate the midpoint
        if (vec[mid] == target) {
            return mid; // Return the index of the target
        } else if (vec[mid] > target) {
            j = mid - 1; // Narrow the search to the left half
        } else {
            i = mid + 1; // Narrow the search to the right half
        }
    }

    return -1; // If not found, return -1
}

int main() {
    vector<int> vec = {1, 3, 4, 2, 5, 6, 7, 9, 10};
    sort(vec.begin(), vec.end()); // Ensure the vector is sorted before search
    int tar = 9;

    int result = binary(vec, tar); // Call the binary search function
    cout << result; // Print the result
    return 0; // Return 0 to indicate successful execution
}