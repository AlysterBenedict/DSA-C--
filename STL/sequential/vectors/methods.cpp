#include <iostream>
#include <vector>

using namespace std;

void printVectorInfo(const vector<int>& vec, const string& message) {
    cout << "\n" << message << ":" << endl;
    cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << endl;
    cout << "Elements: ";
    for(int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Create an empty vector of integers
    vector<int> vec;
    
    printVectorInfo(vec, "Initial state");
    
    // 1. push_back - add elements to the end
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    printVectorInfo(vec, "After push_back operations");

    // 2. emplace_back - construct element in-place
    vec.emplace_back(40);
    vec.emplace_back(50);
    printVectorInfo(vec, "After emplace_back operations");

    // 3. Element access - at() vs []
    cout << "\nElement access:" << endl;
    cout << "vec[2]: " << vec[2] << endl;          // No bounds checking
    cout << "vec.at(3): " << vec.at(3) << endl;    // With bounds checking
    
    // Uncomment to see bounds checking in action
    // cout << vec.at(10) << endl;

    // 4. front() and back()
    cout << "\nFirst element (front): " << vec.front() << endl;
    cout << "Last element (back): " << vec.back() << endl;

    // 5. pop_back - remove last element
    vec.pop_back();
    printVectorInfo(vec, "After pop_back operation");

    // Additional operations from second image
    // 6. erase - remove elements
    vec.erase(vec.begin() + 1); // Remove element at position 1 (20)
    printVectorInfo(vec, "After erasing element at position 1");

    // 7. insert - add element at specific position
    vec.insert(vec.begin() + 1, 25); // Insert 25 at position 1
    printVectorInfo(vec, "After inserting 25 at position 1");

    // 8. clear - remove all elements
    cout << "\nBefore clear:" << endl;
    cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << endl;
    
    vec.clear();
    
    cout << "\nAfter clear:" << endl;
    cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << endl;
    cout << "Note: Capacity remains the same after clear!" << endl;

    // 9. empty - check if vector is empty
    cout << "\nIs vector empty? " << (vec.empty() ? "Yes" : "No") << endl;

    // Demonstrate capacity growth
    cout << "\nDemonstrating capacity growth:" << endl;
    vector<int> growth_vec;
    for(int i = 0; i < 20; i++) {
        growth_vec.push_back(i);
        cout << "Size: " << growth_vec.size() 
             << ", Capacity: " << growth_vec.capacity() << endl;
    }
    
    return 0;
}