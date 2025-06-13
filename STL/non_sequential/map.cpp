#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<string,int> m;
    m["tv"]=50;
    m["tv"]=100; //replaces the value if duplicate key is found
    m["tablet"]=10;
    m["mobile"]=20;
    m["watch"]=15;

    //insert
    m.insert({"speaker",20});
    m.emplace("pc",10);

//print count:
cout<<"count= "<<m.count("tablet")<<endl; //prints the no. of instances of the key(not 100 value)
//print value
cout<<"value = "<<m["tv"];

m.erase("tv");
cout<<endl;

     for ( auto pair : m) {
        cout << pair.first << ": " << pair.second << "\n"; //prints in ascending order of the key(lexicographical)
    }

    //find: returns iterator

    auto it = m.find("tv");  
if (it != m.end()) {  // True if "tv" exists
    cout << "Found: " << it->second;  // Prints 100
} else {
    cout << "Not found!";
}

}