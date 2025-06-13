#include<iostream>
#include<utility>
#include<vector>
using namespace std;
int main()
{
    pair<int,int>p={1,2};
    cout<<p.first<<" "<<p.second<<endl;
    //an element of a pair can be of any datatype
    //pair of pairs:
    pair<string, pair<int,float>>p2={"alyster",{ 8 , 6.2}};
    cout<<p2.first<<" "<<p2.second.first<<" "<<p2.second.second;


    vector<pair<int, int>> vec = {{1, 2}, {2, 3}, {3, 4}};

    vec.push_back({4, 5}); //insert
    vec.emplace_back(4, 5); //in-place objects create

    for(auto p : vec) { // auto Instead of `for (pair<int,int> p : vec)`
        cout << p.first << " " << p.second << endl;
    }

}