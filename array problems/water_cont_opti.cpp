#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<cmath>
using namespace std;

int volume(vector<int>&height)
{
    int n=height.size();
    int max_volume=0;
    int height_container,width;
  int *ptr1=&height[0];
  int *ptr2=&height[n-1];
  while(ptr1<ptr2)
  {
    height_container=min(*ptr1,*ptr2);
    width=ptr2-ptr1;
    max_volume=max(max_volume,height_container*width);
    if(*ptr1<*ptr2)
    ptr1++;
    else
    ptr2--;
  }
  return max_volume;

}


int main()
{
    int n;
    cout<<"Enter the container size : ";
    cin>>n;
    vector<int> height(n);
    cout<<"Enter the heights of the container : ";
    for(int i=0;i<n;i++)
    {
        cin>>height[i];
    }
    cout<<"The maximum volume of the container is : "<<volume(height)<<endl;
    return 0;
}