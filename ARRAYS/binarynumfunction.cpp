#include<iostream>
#include<vector>
using namespace std;
int binary(vector<int> &vec, int target){
    int i=0;
    int j=vec.size()-1;
    bool binary2=false;
    while(i<=j){
        int mid=(i+j)/2;
        if(target>vec[mid]){
            i=mid+1;
        }
        else if(target<vec[mid]){
            j=mid-1;
        }
        else if(target==vec[mid]){
            cout<<mid;
            break;
            binary2=true;
        }
    }
    if(!binary2){
        cout<<-1;
    }
}
int main(){
    vector<int> vec={1,3,4,2,5,6,7,9,10};
    int tar=9;
  cout<<binary(vec,tar);
}