#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size();
        int left =0;
        int right = n-1;
        int maxArea=0;
        
        

        while(left < right)
        {
            int width=right-left;
            int h= min(height[left], height[right]);
            int currentArea= width *h;
            maxArea= max(maxArea, currentArea);

            if(height[left] < height[right])
            left++;
            else
            right--;

        }return maxArea;
    }
};

// Main function to test the code
int main() {
    Solution sol;
    
    vector<int> h1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Input: {1, 8, 6, 2, 5, 4, 8, 3, 7}" << endl;
    cout << "Max Area: " << sol.maxArea(h1) << endl; // Expected: 49

    cout << "--------------------" << endl;

    vector<int> h2 = {1, 1};
    cout << "Input: {1, 1}" << endl;
    cout << "Max Area: " << sol.maxArea(h2) << endl; // Expected: 1
    
    return 0;
}