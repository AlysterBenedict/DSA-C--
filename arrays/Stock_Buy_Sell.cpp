#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
        return 0;

        int min_price=prices[0];
        int max_profit=0;

        for(int i=1;i<prices.size();i++)
        {
            int profit=prices[i]-min_price;
            max_profit=max(max_profit,profit);
            min_price=min(prices[i],min_price);
        }
        return max_profit;
    }
    
};

int main() {
    Solution sol;

    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << sol.maxProfit(prices1) << endl;

    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << sol.maxProfit(prices2) << endl;

    return 0;
}
