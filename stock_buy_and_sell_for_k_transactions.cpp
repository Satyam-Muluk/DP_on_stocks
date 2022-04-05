#include<bits/stdc++.h>
using namespace std;


int maxProfit(vector<int> &prices,int index,int buyornot,int capacity,vector<vector<vector<int>>> &dp)
{
    if(index==prices.size() or capacity==0)
      return 0;
    

    if(dp[index][buyornot][capacity]!=-1)
    return dp[index][buyornot][capacity];
    int profit = 0;
    if(buyornot)
    {
        int buy = -prices[index] +  maxProfit(prices,index+1,0,capacity,dp);
        int notbuy = maxProfit(prices,index+1,1,capacity,dp);
        profit = max(buy,notbuy);
    }
    else
    {
       int sell = prices[index]+maxProfit(prices,index+1,1,capacity-1,dp);
       int notsell = maxProfit(prices,index+1,0,capacity,dp);
       profit = max(sell,notsell);
    }
    return dp[index][buyornot][capacity] = profit;
}
int main()
{
    vector<int> prices = {3,2,6,5,0,3};
    int k = 2;

    //here k transactions ,therefore dp matrix
    //dp[N][2][k+1].
    
    vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
    cout<<maxProfit(prices,0,1,k,dp);
}