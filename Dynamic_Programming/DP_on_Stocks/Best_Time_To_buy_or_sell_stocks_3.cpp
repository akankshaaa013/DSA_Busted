#include <bits/stdc++.h>
using namespace std;

// 1 transaction = buying + selling

// Memoization
// T.C -> O(2*n*capacity)
// S.C -> O(n) + O(n * 2 * capacity)
int solve(int idx, int buy, int cap, vector<int> &prices, int n, vector<vector<vector<int>>> &dp)
{
    if (idx == n || cap == 0)
        return 0;

    if (dp[idx][buy][cap] != -1)
        return dp[idx][buy][cap];

    int profit = 0;

    if (buy)
    {
        profit = max(-prices[idx] + solve(idx + 1, 0, cap, prices, n, dp),
                     0 + solve(idx + 1, 1, cap, prices, n, dp));
    }
    else
    {
        profit = max(prices[idx] + solve(idx + 1, 1, cap - 1, prices, n, dp),
                     0 + solve(idx + 1, 0, cap, prices, n, dp));
    }
    return dp[idx][buy][cap] = profit;
}

// Tabulation
// T.C -> O(2*n*capacity)
// S.C -> O(n * 2 * capacity)
int solveT(int capacity, vector<int> &prices, int n, vector<vector<vector<int>>> &dp)
{

    // dp is already initialized with 0 so no need for base case.
    for(int idx = n - 1; idx >= 0; idx--)
    {
        for(int buy = 0; buy <= 1; buy++)
        {
            for(int cap = 1; cap <= capacity; cap++)
            {
                int profit = 0;

                if (buy)
                {
                    profit = max(-prices[idx] + dp[idx + 1][0][cap], 0 + dp[idx + 1][1][cap]);
                }
                else
                {
                    profit = max(prices[idx] + dp[idx + 1][1][cap - 1], 0 + dp[idx + 1][0][cap]);
                }
                dp[idx][buy][cap] = profit;
            }
        }
    }
    return dp[0][1][capacity];
}


// Space Optimization
// T.C -> O(2*n*capacity)
// S.C -> O(2 * (2 * capacity)) = O(4*capacity)
int solveSO(int capacity, vector<int> &prices, int n)
{
    vector<vector<int>> ahead(2, vector<int>(capacity + 1, 0)), curr(2, vector<int>(capacity + 1, 0));

    for(int idx = n - 1; idx >= 0; idx--)
    {
        for(int buy = 0; buy <= 1; buy++)
        {
            for(int cap = 0; cap <= capacity; cap++)
            {
                int profit = 0;

                if (buy)
                {
                    profit = max(-prices[idx] + ahead[0][cap], 0 + ahead[1][cap]);
                }
                else
                {
                    profit = max(prices[idx] + ahead[1][cap - 1], 0 + ahead[0][cap]);
                }
                curr[buy][cap] = profit;
            }
        }
        ahead = curr;
    }
    return ahead[1][capacity];
}

int maxProfit(vector<int> &prices, int capacity)
{
    int n = prices.size();

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(3, vector<int>(capacity + 1, 0)));

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