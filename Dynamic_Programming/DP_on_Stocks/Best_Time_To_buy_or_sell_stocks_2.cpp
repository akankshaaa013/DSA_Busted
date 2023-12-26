#include <bits/stdc++.h>
using namespace std;

// Memoization
// T.C -> O(2*n)
// S.C -> O(n) + O(n * 2)
int solve(int idx, int buy, int n, vector<int> &prices, vector<vector<int>> &dp)
{
    if (idx == n)
        return 0;

    if (dp[idx][buy] != -1)
        return dp[idx][buy];

    int profit = 0;

    if (buy)
    {
        profit = max(-prices[idx] + solve(idx + 1, 0, n, prices, dp),
                     0 + solve(idx + 1, 1, n, prices, dp));
    }
    else
    {
        profit = max(prices[idx] + solve(idx + 1, 1, n, prices, dp),
                     0 + solve(idx + 1, 0, n, prices, dp));
    }
    return dp[idx][buy] = profit;
}

// Tabulation
// T.C -> O(2*n)
// S.C -> O(n * 2)
int solveT(int n, vector<int> &prices, vector<vector<int>> &dp)
{

    dp[n][0] = dp[n][1] = 0;

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            int profit = 0;

            if (buy)
            {
                profit = max(-prices[idx] + dp[idx + 1][0], 0 + dp[idx + 1][1]);
            }
            else
            {
                profit = max(prices[idx] + dp[idx + 1][1], 0 + dp[idx + 1][0]);
            }
            dp[idx][buy] = profit;
        }
    }
    return dp[0][1];
}

// Space Optimization
// T.C -> O(2*n)
// S.C -> O(1)
int solveSO(int n, vector<int> &prices)
{
    vector<int> ahead(2, -1), curr(2, -1);

    ahead[0] = ahead[1] = 0;

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            int profit = 0;

            if (buy)
            {
                profit = max(-prices[idx] + ahead[0], 0 + ahead[1]);
            }
            else
            {
                profit = max(prices[idx] + ahead[1], 0 + ahead[0]);
            }
            curr[buy] = profit;
        }
        ahead = curr;
    }
    return ahead[1];
}

// Space Optimization - 2 (using variables)
// T.C -> O(2*n)
// S.C -> O(1)
int solveSO2(int n, vector<int> &prices)
{
    int aheadNotBuy, aheadBuy, currNotBuy, currBuy;

    aheadNotBuy = aheadBuy = 0;

    for (int idx = n - 1; idx >= 0; idx--)
    {
        currBuy = max(-prices[idx] + aheadNotBuy, 0 + aheadBuy);
        currNotBuy = max(prices[idx] + aheadBuy, 0 + aheadNotBuy);

        aheadBuy = currBuy;
        aheadNotBuy = currNotBuy;
    }
    return aheadBuy;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> dp(n + 1, vector<int>(2, -1));

    return solveSO2(n, prices);
}

int main()
{
    int n;
    cout << "Enter the total days : ";
    cin >> n;

    cout << "Enter the stock prices on i-th day : ";

    vector<int> price;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        price.push_back(x);
    }

    cout << "Max Profit earned is : " << maxProfit(price);
}