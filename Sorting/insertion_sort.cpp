#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int curr = arr[i];  
        int prev = i - 1;

        // Shift elements to the right to make space for `curr`
        while (prev >= 0 && arr[prev] > curr) {
            arr[prev + 1] = arr[prev];  
            prev--;
        }
        arr[prev + 1] = curr;  // Place `curr` at correct position
    }
}

int main() {
    vector<int> arr;
    int n, num;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the " << n << " elements: ";

    for (int i = 0; i < n; i++) { 
        cin >> num;
        arr.push_back(num);
    }
    insertionSort(arr);

    // Print the sorted array
    cout << "\nSorted Array: ";
    for (int nums : arr) {
        cout << nums << " ";
    }
    cout << endl;

    return 0;
}