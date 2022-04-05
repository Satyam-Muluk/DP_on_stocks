#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices,int index,int buyornot,int fee,vector<vector<int>> &dp)
{
    if(index==prices.size())
      return 0;
    
    if(dp[index][buyornot]!=-1)
      return dp[index][buyornot];
    int profit = 0;
    if(buyornot)
    {
       int buy = -prices[index]+maxProfit(prices,index+1,0,fee,dp);
       int notbuy = maxProfit(prices,index+1,1,fee,dp);
       profit = max(buy,notbuy);
    }
    else
    {
        // transaction fee is subtracted after transaction is carried out
        int sell = prices[index] - fee + maxProfit(prices,index+1,1,fee,dp);
        int notsell = maxProfit(prices,index+1,0,fee,dp);
        profit = max(sell,notsell);

    }
    return dp[index][buyornot] = profit;
}


int main()
{
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;
   // here for each transaction a transaction fee is added, that is after each transaction we need to deduct a transaction fee from the profit.
    vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
    cout<<maxProfit(prices,0,1,fee,dp);
}