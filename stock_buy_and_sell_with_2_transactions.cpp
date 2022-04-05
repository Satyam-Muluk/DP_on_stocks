#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices,int index,int buyornot,int capacity,vector<vector<vector<int>>>&dp)
{
    if(index==prices.size() or capacity==0)
     return 0;
    
    // check if solution for the current state exists
    if(dp[index][buyornot][capacity]!=-1) 
    return dp[index][buyornot][capacity];
    int profit = 0;
    if(buyornot)
    {
       int buy = -prices[index]+maxProfit(prices,index+1,0,capacity,dp);
       //we buy a stock therefore switch the value of buyornot to 0 which means we cannot buy it further unless we sell it.
       int notbuy = maxProfit(prices,index+1,1,capacity,dp);
       // we didn't buy a stock there fore keep the value of buyornot as 1 inorder to purchase the stock.
       profit = max(buy,notbuy);
    }
    else
    {
        int sell = prices[index]+maxProfit(prices,index+1,1,capacity-1,dp);
        //we sold a stock , therefore make buyornot as 1 => indicates we can buy a stock.
        int notsell = maxProfit(prices,index+1,0,capacity,dp);
        profit = max(sell,notsell);
    }
    return dp[index][buyornot][capacity] = profit;
}


int main()
{
    vector<int> prices = {1,2,3,4,5};
    // here only 2 transactions are allowed
    // so the changing parameters are 
    //1.) index , 2) whether to buyornot 3) capacity==2
    //as there are 3 changing parameters we need a 3d vector
    // whether to buy or not specifies that , if we buy a stock then we first have to sell it and then buy the next stock
    // initially buyornot=1 which means we can buy a stock ,but once we buy a stock then make the value of buyornot as 0 which means we cannot buy it further,first we have to sell it


    vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
    cout<<maxProfit(prices,0,1,2,dp);
}