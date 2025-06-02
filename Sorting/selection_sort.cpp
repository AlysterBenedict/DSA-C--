#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<limits.h>
using namespace std;



void inputArray(vector<int>& arr) {
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

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;  
        
        for (int j = i + 1; j < n; j++) {  
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        swap(arr[i], arr[minIndex]); 
    }
}




int main() {
    vector<int> arr;
    
    inputArray(arr);
    
    selectionSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
