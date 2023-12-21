#include <bits/stdc++.h>
using namespace std;

int solve(int idx, int target, vector<int> &coins, vector<vector<int>> &dp)
{
    if (target == 0)
        return 1;

    if (idx == 0)
    {
        if (target % coins[0] == 0)
            return 1;
        return 0;
    }
    if (dp[idx][target] != -1)
        return dp[idx][target];

    int notTake = solve(idx - 1, target, coins, dp);

    int take = 0;
    if (coins[idx] <= target)
        take = solve(idx, target - coins[idx], coins, dp);

    return dp[idx][target] = take + notTake;
}

int solveT(int n, int target, vector<int> &coins, vector<vector<int>> &dp)
{

    for (int i = 0; i < n; i++)
        dp[i][0] = 1;

    for (int tar = 0; tar <= target; tar++)
    {
        if (tar % coins[0] == 0)
            dp[0][tar] = 1;
        else
            dp[0][tar] = 0;
    }

    for (int idx = 1; idx < n; idx++)
    {
        for (int tar = 0; tar <= target; tar++)
        {
            int notTake = dp[idx - 1][tar];

            int take = 0;
            if (coins[idx] <= tar)
                take = dp[idx][tar - coins[idx]];

            dp[idx][tar] = take + notTake;
        }
    }
    return dp[n - 1][target];
}

int solveSO(int n, int target, vector<int> &coins)
{
    vector<int> prev(target + 1, 0);

    prev[0] = 1;

    for (int tar = 0; tar <= target; tar++)
    {
        if (tar % coins[0] == 0)
            prev[tar] = 1;
        else
            prev[tar] = 0;
    }

    for (int idx = 1; idx < n; idx++)
    {
        // vector<int> curr(target + 1, 0);
        // curr[0] = 1;
        for (int tar = 0; tar <= target; tar++)
        {
            int notTake = prev[tar];

            int take = 0;
            if (coins[idx] <= tar)
                take = prev[tar - coins[idx]];

            prev[tar] = take + notTake;
        }
        // prev = curr;
    }
    return prev[target];
}

int change(int amount, vector<int> &coins)
{

    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    return solveSO(n, amount, coins);
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
         << "No. of combinations of the coin that makes up to the amount : " << change(amt, coins) << endl;
}