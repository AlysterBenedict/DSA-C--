#include<iostream>
#include<list>
using namespace std;

//implemented like a doulbly linked list  //random access not available (l[2] not possible)
//wheres vector is implemented as a dynamic array
int main()
{
    list<int> l;
    l.push_back(1);
    l.push_front(3);
    l.push_back(4);  //also emplace can be used
    l.push_front(2);

    l.pop_back();
    l.pop_front();
    for(int num : l)
    {
        cout<<num<<" ";
    }
} 