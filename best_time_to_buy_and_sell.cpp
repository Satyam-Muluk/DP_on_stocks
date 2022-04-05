#include<bits/stdc++.h>
using namespace std;


int maxProfit(vector<int> &prices)
{

    // approach:
    // 1. assume 1st element as min element.
    // 2. in for loop check each element and update the profit and minelement found so far.
    
    int mincost = prices[0];
    int profit = 0;
    for(auto it:prices)
    {
        int temp = it-mincost;
        profit = max(profit,temp);
        mincost = min(mincost,it);
    }
    return profit;
}

int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    cout<<maxProfit(prices);
}