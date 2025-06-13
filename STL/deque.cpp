//deque-Double ended Queue //implements
#include<iostream>
#include<deque>
using namespace std;


// implemented as a dynamic array  //random access of elements like d[3] is legal
int main()
{
    deque<int> d;
    d.push_back(1);
    d.push_front(3);
    d.push_back(4);  //also emplace can be used
    d.push_front(2);

    d.pop_back();
    d.pop_front();
    for(int num : d)
    {
        cout<<num<<" ";
    }
} 