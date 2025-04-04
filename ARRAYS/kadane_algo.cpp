//  Brute force 

//MAXIMUM SUBARRAY SUM
#include<iostream>
#include <climits>
using namespace std;

int main() {
    int arr[] = {25,-98,89,-54,45};
    int n = sizeof(arr) / sizeof(int);
    int maxsum = INT_MIN; 
    int cursum;

    for (int start = 0; start < n; start++) {
        cursum = 0; 
        for (int end = start; end < n; end++) {
            cursum += arr[end];
            maxsum = max(cursum, maxsum);
        }
    }

    cout << "The max subarray sum is: " << maxsum << endl;
    return 0;
}
