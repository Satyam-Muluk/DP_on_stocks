#include<bits/stdc++.h>
using namespace std;


int maxProfit(vector<int> &prices,int index,int buyornot,vector<vector<int>> &dp)
{
    if(index==prices.size())
    {
        return 0;
    }
    if(dp[index][buyornot]!=-1)
       return dp[index][buyornot];
    int profit = 0;
    if(buyornot)
    {
        // profit = s.p - c.p here we are adding -c.p therefore -prices[index]
        int buy = -prices[index]+maxProfit(prices,index+1,0,dp);
        int notbuy = maxProfit(prices,index+1,1,dp);
        profit = max(buy,notbuy);
    }
    else
    {  
        int sell = prices[index]+maxProfit(prices,index+1,1,dp);
        int notsell = maxProfit(prices,index+1,0,dp);
        profit = max(sell,notsell);
    }
    return dp[index][buyornot] = profit;
}
int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
    cout<<maxProfit(prices,0,1,dp);
}