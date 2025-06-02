#include<iostream>
#include<vector>
#include<utility>
using namespace std;



void inputArray(std::vector<int>& arr) {
    int num;
   cout<<"Enter the size : ";
   cin>>num;
   int i=0,value;
   while(i<num)
   {
    cin>>value;
    arr.push_back(value);
    i++;
   }
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); // Swap elements if they are in the wrong order
            }
        }
    }
}




int main() {
    vector<int> arr;
    
    // Input the array from user
    inputArray(arr);
    
    // Sort the array using bubble sort
    bubbleSort(arr);
    
    // Output the sorted array
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}

