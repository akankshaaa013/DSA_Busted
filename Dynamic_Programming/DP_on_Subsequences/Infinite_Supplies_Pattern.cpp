#include <bits/stdc++.h>
using namespace std;

// T.C - O(target * n)
// S.C - O(target) + O(target * n)
// MEMOIZATION
int solve(int idx, int target, vector<int> &coins, vector<vector<int>> &dp)
{
    if (target == 0)
        return 0;

    if (idx == 0)
    {
        if (target % coins[0] == 0)
            return target / coins[0];

        return 1e9;
    }

    if (dp[idx][target] != -1)
        return dp[idx][target];

    int notTake = 0 + solve(idx - 1, target, coins, dp);

    int take = INT_MAX;

    if (coins[idx] <= target)
        take = 1 + solve(idx, target - coins[idx], coins, dp);

    return dp[idx][target] = min(take, notTake);
}

// T.C - O(target * n)
// S.C - O(target * n)
// TABULATION
int solveT(int n, int tar, vector<int> &coins, vector<vector<int>> &dp)
{
    for (int T = 0; T <= tar; T++)
    {
        if (T % coins[0] == 0)
            dp[0][T] = T / coins[0];
        else
            dp[0][T] = 1e9;
    }

    for (int idx = 1; idx < n; idx++)
    {
        for (int target = 0; target <= tar; target++)
        {
            int notTake = 0 + dp[idx - 1][target];

            int take = INT_MAX;

            if (coins[idx] <= target)
                take = 1 + dp[idx][target - coins[idx]];

            dp[idx][target] = min(take, notTake);
        }
    }

    return dp[n - 1][tar];
}

// T.C - O(target * n)
// S.C - O(target)
// SPACE OPTIMIZATION USING A SINGLE ARRAY.
int solveSO(int n, int tar, vector<int> &coins)
{

    vector<int> prev(tar + 1, 1e9);

    for (int T = 0; T <= tar; T++)
    {
        if (T % coins[0] == 0)
            prev[T] = T / coins[0];
    }

    for (int idx = 1; idx < n; idx++)
    {
        // vector<int> curr(tar + 1, 1e9);
        for (int target = 0; target <= tar; target++)
        {
            int notTake = 0 + prev[target];

            int take = INT_MAX;

            if (coins[idx] <= target)
                take = 1 + prev[target - coins[idx]];

            prev[target] = min(take, notTake);
        }
        // prev = curr;
    }
    return prev[tar];
}

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

    int ans = solve(n - 1, amount, coins, dp);

    return ans >= 1e9 ? -1 : ans;
}

int main()
{

    int n, amt;
    cout << "Enter the no. of unique coins & total amt: ";
    cin >> n >> amt;

    vector<int> coins;

    cout << "Enter the coin denominations : ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        coins.push_back(x);
    }

    cout << endl
         << "Minimum coins required to achieve the target is : " << coinChange(coins, amt) << endl;
}