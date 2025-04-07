#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int profit(vector<int>& prices)
{
    int minPrice = INT_MAX;
    int maxProfit = 0;
    for (int price : prices) {
        if (price < minPrice)
            minPrice = price;
        else if (price - minPrice > maxProfit)
            maxProfit = price - minPrice;
    }
    return maxProfit;
}





int main()
{
    int n;
    cout<<"Enter the number of days : ";
    cin>>n;
    vector<int> prices(n);
    cout<<"Enter the prices of stock for "<<n<<" days : ";
    for(int i=0;i<n;i++)
    {
        cin>>prices[i];

    }
    int result=profit(prices); //function call
    cout<<"The maximum profit is : "<<result<<endl; //output the result

}