#include <bits/stdc++.h>
using namespace std;

// 1 transaction = buying + selling

// Memoization
// T.C -> O(n*totalTransac)
// S.C -> O(n) + O(n*totalTransac)
int solve(int idx, int totalTransac, int cap, vector<int> &prices, int n, vector<vector<int>> &dp)
{
    if (idx == n || cap == totalTransac)
        return 0;

    if (dp[idx][totalTransac] != -1)
        return dp[idx][totalTransac];

    int profit = 0;

    if (totalTransac % 2 == 0)
    {
        profit = max(-prices[idx] + solve(idx + 1, totalTransac + 1, cap, prices, n, dp),
                     0 + solve(idx + 1, totalTransac, cap, prices, n, dp));
    }
    else
    {
        profit = max(prices[idx] + solve(idx + 1, totalTransac + 1, cap, prices, n, dp),
                     0 + solve(idx + 1, totalTransac, cap, prices, n, dp));
    }
    return dp[idx][totalTransac] = profit;
}

// Tabulation
// T.C -> O(n*totalTransac)
// S.C -> O(n*totalTransac)
int solveT(int cap, vector<int> &prices, int n, vector<vector<int>> &dp)
{

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int totalTransac = cap * 2 - 1; totalTransac >= 0; totalTransac--)
        {
            int profit = 0;

            if (totalTransac % 2 == 0)
            {
                profit = max(-prices[idx] + dp[idx + 1][totalTransac + 1],
                             0 + dp[idx + 1][totalTransac]);
            }
            else
            {
                profit = max(prices[idx] + dp[idx + 1][totalTransac + 1],
                             0 + dp[idx + 1][totalTransac]);
            }
            dp[idx][totalTransac] = profit;
        }
    }
    return dp[0][0];
}

// Space Optimization
// T.C -> O(n*totalTransac)
// S.C -> O(totalTransac * 2)
int solveSO(int cap, vector<int> &prices, int n)
{
    vector<int> ahead(cap * 2 + 1, 0), curr(cap * 2 + 1, 0);

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int totalTransac = cap * 2 - 1; totalTransac >= 0; totalTransac--)
        {
            int profit = 0;

            if (totalTransac % 2 == 0)
            {
                profit = max(-prices[idx] + ahead[totalTransac + 1],
                             0 + ahead[totalTransac]);
            }
            else
            {
                profit = max(prices[idx] + ahead[totalTransac + 1],
                             0 + ahead[totalTransac]);
            }
            curr[totalTransac] = profit;
        }
        ahead = curr;
    }
    return ahead[0];
}

int maxProfit(vector<int> &prices, int capacity)
{
    int n = prices.size();

    vector<vector<int>> dp(n + 1, vector<int>(capacity * 2 + 1, 0));

    // return solve(0, 0, capacity*2, prices, n, dp);
    return solveSO(capacity, prices, n);
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

    int cap;
    cout << "Enter the transaction limit : ";
    cin >> cap;

    cout << "Max Profit earned is : " << maxProfit(price, cap);
}