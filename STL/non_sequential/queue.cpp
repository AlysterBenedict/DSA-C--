#include<iostream>
#include<queue>
using namespace std;

int main() {
    queue<int> s;
    s.push(1); //emplace also can be used
    s.push(2);
    s.push(3);
    s.push(4);

cout<<"size of the stack : "<<s.size()<<endl;

//using swap:
queue<int>s2;
s2.swap(s);
cout<<"size of the stack 1 : "<<s.size()<<endl;
cout<<"size of the stack 2 : "<<s2.size()<<endl;

    while (!s2.empty()) {
        cout << s2.front() << " ";  // Print the first element of the queue
        s2.pop();                 // Remove it
    }
    // Output: 4 3 2 1 (LIFO order)
    return 0;
}
