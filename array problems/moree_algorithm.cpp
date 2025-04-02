#include<iostream>
#include<vector>
using namespace std;
//finds the majority element in an array using Moore's voting algorithm
// The majority element is the element that appears more than n/2 times in the array
    int majorityElement(vector<int>& nums) {
        int freq,ans;
        freq=0;
        for(int i=0;i<nums.size();i++)
        {
            if(freq==0)
            {
                ans=nums[i];
            }
            if(ans==nums[i])
            {
                freq++;
            }else
            {
                freq--;
            }
        }


        int count=0;
        for(int val : nums)
        {
            if(val==ans)
            {
                count++;
            }

        }
        if(count>(nums.size()/2))
        return ans;
        else
        return -1;
    
    }

    int main()
    {
        vector<int> nums={2,2,1,2,1,3,4,2,2,2};
        int ans=majorityElement(nums);
        cout<<"The majority element is : "<<ans<<endl;
    }