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


    // Moore's Voting Algorithm - Intuition:
//
// The idea is simple but smart:
//
// If there is a majority element (appearing more than n/2 times),
// it will survive all the "cancellations" that happen with other elements.
//
// We simulate a voting system:
// - If we see the same element as our current candidate, we vote +1 (freq++)
// - If we see a different element, we cancel a vote (freq--)
//
// When freq becomes 0, it means our candidate has been canceled out,
// so we pick the current element as a new candidate.
//
// At the end of this loop, the candidate stored in 'ans' *might* be the majority element.
// Therefore, we must verify it by counting its occurrences.
//
// The second loop counts how many times 'ans' appears.
// If it appears more than n/2 times, it's the true majority.
// Otherwise, there is no majority element and we return -1.
