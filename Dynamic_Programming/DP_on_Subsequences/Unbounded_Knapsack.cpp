#include<bits/stdc++.h>
using namespace std;

int solve(int idx, int wgt, vector<int> &profit, vector<int> &weight, vector<vector<int>>& dp)
{
    if(wgt == 0)    return 0;

    if(idx == 0)
    {
        if(weight[0] <= wgt)    return (wgt/weight[0])*(profit[0]);
        return 0;
    }
    if(dp[idx][wgt] != -1)  return dp[idx][wgt];

    int notTake = 0 + solve(idx - 1, wgt, profit, weight, dp);

    int take = -1e9;

    if(weight[idx] <= wgt)  take = profit[idx] + solve(idx, wgt - weight[idx], profit, weight, dp);

    return dp[idx][wgt] = max(take, notTake);
}

int solveT(int n, int wgt, vector<int> &profit, vector<int> &weight, vector<vector<int>>& dp)
{
    for(int W = 0; W <= wgt; W++)
    {
        if(W >= weight[0])    dp[0][W] = (W/weight[0])*(profit[0]);
        else dp[0][W] = 0;
    }

    for(int idx = 1; idx < n; idx++)
    {
        for(int W = 0; W <= wgt; W++)
        {
            int notTake = 0 + dp[idx - 1][W];

            int take = -1e9;

            if(weight[idx] <= W)  take = profit[idx] + dp[idx][W - weight[idx]];

            dp[idx][W] = max(take, notTake);
        }
    }
    return dp[n-1][wgt];
}


int solveSO(int n, int wgt, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(wgt + 1, 0);
    for(int W = 0; W <= wgt; W++)
    {
        if(W >= weight[0])    prev[W] = (W/weight[0])*(profit[0]);
        else prev[W] = 0;
    }

    for(int idx = 1; idx < n; idx++)
    {
        // vector<int> curr(wgt + 1, 0);
        for(int W = 0; W <= wgt; W++)
        {
            int notTake = 0 + prev[W];

            int take = -1e9;

            if(weight[idx] <= W)  take = profit[idx] + prev[W - weight[idx]];

            prev[W] = max(take, notTake);
        }
        // prev = curr;
    }
    return prev[wgt];
}

int unboundedKnapsack(int n, int W, vector<int> &profit, vector<int> &weight){
    
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    return solveSO(n, W, profit, weight);
}


int main(){  

    int n, wt;

    cout<<"Enter the value of n & maxWeight : ";
    cin >> n >> wt;

    vector<int> weight(n), value(n);

    cout<<"Enter the weight value pair : ";
    for(int i = 0; i < n; i++)
    {
        int x,y;
        cin >> x >> y;
        weight[i] = x;
        value[i] = y;
    }
    cout<<endl<<"Max Profit is : " << unboundedKnapsack(n, wt, value, weight);
}