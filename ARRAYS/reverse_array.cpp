#include <iostream>
using namespace std;

// Function to reverse the array
void reverse(int arr[], int size)
{
    int start = 0, end = size - 1;
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the element at the position " << (i + 1) << ": ";
        cin >> arr[i];
    }

    // Call the reverse function and pass size as a parameter
    reverse(arr, size);

    cout << "Reversed array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}