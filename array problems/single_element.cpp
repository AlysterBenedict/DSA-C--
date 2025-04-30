#include<iostream>
#include<vector>
using namespace std;

        int singleElement(vector<int>& arr) {
            int n = arr.size();
            int st = 0, end = n - 1;
    
            while (st < end) { 
                int mid = st + (end - st) / 2;
    
                // Check if `mid` is unique
                if (mid > 0 && mid < n - 1 && arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) {
                    return arr[mid];
                }
    
                // Adjusting partition logic to correctly handle pairs
                if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) || (mid % 2 == 1 && arr[mid] == arr[mid - 1])) {
                    st = mid + 1; // Move to the right half
                } else {
                    end = mid-1; // Stay in the left half
                }
            }
    
            
            return arr[st];
        }


int main()
{
    vector<int> arr;
    cout<<"Enter the size of the array: ";
    int n;
    cin>>n;
    int i=0;
    cout<<"ENter the elements of the array : ";
    while(i<n)
    {
        int x;
        cin>>x;
        arr.push_back(x);
        i++;
    }
    int ans=singleElement(arr);
    cout<<"The single element is at index : "<<ans<<endl;
    cout<<"The Single element is : "<<arr[ans]<<endl;
}