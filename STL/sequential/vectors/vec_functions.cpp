#include<iostream>
#include<vector>
using namespace std;
int main()
{
   
    vector <int> vec1={1,2,3,4,5};
    //Vector Push_back function
    vec1.push_back(6);            //adds size to vector at runtime
    vec1.push_back(7);          //cannot be done with the normal array
    vec1.push_back(8);
    vec1.push_back(9);          //Static-->stack memory  Dynamic-->heap memory
    vec1.push_back(10);
    vec1.push_back(20);


    for(int i: vec1)
    {
        cout<<i<<" ";
    }

    //Vector Pop function
    vec1.pop_back(); //removes the last element

    for(int i: vec1)
    {
        cout<<i<<" ";
    }

cout<<endl;

    cout<<"capacity of vector is : "<<vec1.capacity()<<endl; //total internal mem block
    cout<<"max size of vector is : "<<vec1.max_size()<<endl;
    cout<<"front element of vector is : "<<vec1.front()<<endl;
    cout<<"back element of vector is : "<<vec1.back()<<endl;
    cout<<"first element of vector is : "<<vec1.at(0)<<endl;
    cout<<"last element of vector is : "<<vec1.at(vec1.size()-1)<<endl;
    cout<<"first element of vector is : "<<vec1[0]<<endl;
    cout<<"last element of vector is : "<<vec1[vec1.size()-1]<<endl;
    cout<<"size of vector is : "<<vec1.size()<<endl;  //total elements
}