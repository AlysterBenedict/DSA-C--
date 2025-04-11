#include <iostream>
#include <vector>
using namespace std;

// Function to search for the target in the rotated sorted array
int search(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1;

    // Continue searching while the range is valid
    while (start <= end) {
        // Calculate the mid index
        int mid = start + (end - start) / 2;

        // Check if the target is found
        if (target == nums[mid])
            return mid;

        // Check if the left half is sorted
        if (nums[start] <= nums[mid]) {
            // If the target lies in the sorted left half
            if (target >= nums[start] && target <= nums[mid])
                end = mid - 1; // Eliminate the right half
            else
                start = mid + 1; // Eliminate the left half
        } else { // Else, the right half must be sorted
            // If the target lies in the sorted right half
            if (target >= nums[mid] && target <= nums[end])
                start = mid + 1; // Eliminate the left half
            else
                end = mid - 1; // Eliminate the right half
        }
    }

    // If no index is found, return -1
    return -1;
}

int main() {
    // Input array
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;
    vector<int> nums(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Input target
    cout << "Enter the target element to search for: ";
    int target;
    cin >> target;

    // Search for the target and print the result
    int result = search(nums, target);

    if (result != -1)
        cout << "Target found at index " << result << endl;
    else
        cout << "Target not found in the array" << endl;

    return 0;
}