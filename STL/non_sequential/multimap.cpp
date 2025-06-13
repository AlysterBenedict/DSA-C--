#include<iostream>
#include<map>
using namespace std;
int main()
{   //allows duplicate keys
    multimap<string,int> m;
    m.emplace("tv",100);
    m.emplace("tv",100);
    m.emplace("tv",100);
    m.emplace("tv",100);


    //to delete a specific instance pass iterator to erase()
        m.erase(m.find("tv"));

    for ( auto pair : m) {
        cout << pair.first << ": " << pair.second << "\n"; //prints in ascending order of the key(lexicographical)
    }
}
