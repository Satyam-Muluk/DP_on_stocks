#include<bits/stdc++.h>
using namespace std;


int maxProfit(vector<int> &prices,int index,int buyornot,vector<vector<int>> &dp)
{
    if(index>=prices.size())
    {
        return 0;
    }

    int profit = 0;
    if(buyornot)
    {
       int buy = -prices[index]+maxProfit(prices,index+1,0,dp);
       int notbuy = maxProfit(prices,index+1,1,dp);
       profit = max(buy,notbuy);


    }
    else
    {
      int sell = prices[index]+maxProfit(prices,index+2,1,dp);
      int notsell = maxProfit(prices,index+1,0,dp);
      profit = max(sell,notsell);

    }
    return dp[index][buyornot] = profit;
}
int main()
{
    vector<int> prices = {1,2,3,0,2};
    vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
    cout<<maxProfit(prices,0,1,dp);
}