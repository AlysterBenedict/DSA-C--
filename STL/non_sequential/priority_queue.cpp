#include<iostream>
#include<queue>
using namespace std;
//uses trees to implement the structure
//push , pop = O(logn) time complexity;

int main() {
    priority_queue<int> s;   //elements are arranged in the decreasing order of their priority
    s.push(1); //emplace also can be used
    s.push(2);
    s.push(3);
    s.push(4);
      while (!s.empty()) {
        cout << s.top() << " ";  // Print the first element of the queue
        s.pop();                 // Remove it
    }
cout<<endl;

//reverse order priority queue
    priority_queue<int,vector<int>,greater<int>> s2;   //elements are arranged in the increasing order of their priority
    s2.push(1); //emplace also can be used
    s2.push(2);
    s2.push(3);
    s2.push(4);
      while (!s2.empty()) {
        cout << s2.top() << " ";  // Print the first element of the queue
        s2.pop();                 // Remove it
    }
}