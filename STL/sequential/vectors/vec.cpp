//vector is array like data structure but can change its size dynamically
//it is part of the C++ standard template library (STL)

//syntax : vec<data_type> vec_name(size);

#include<iostream>
#include<vector>
using namespace std;
int main()
{

    //vector is stored as a dynamic array in the heap memory
    //when a vector is created, it is created with a default size of 0
    //when we add elements to the vector, it is resized to fit the new elements
    //when we remove elements from the vector, it is resized to fit the new elements

    //when a element is added to a vector ,the internal array size is doubled(only if all blocks are full)
    //when a element is removed from a vector ,the internal array size is halved

    vector<int> vec1; //empty vector of size 0
    vector <int> vec2={1,2,3,4,5};
    vector <int> vec3(5,10); //vector of size 5 with all elements initialized to 10
    cout<<vec3[3]<<endl;

    for(int i : vec2)
    {
        cout<<i<<" ";
    }
}
