#include <bits/stdc++.h>
using namespace std;

int solve(int row, int prevcol, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (row == 0)
    {
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (i != prevcol)
                mini = min(mini, grid[0][i]);
        }
        return mini;
    }

    if (dp[row][prevcol] != -1)
        return dp[row][prevcol];

    int mini = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (i == prevcol)
            continue;

        int num = grid[row][i] + solve(row - 1, i, n, grid, dp);
        mini = min(mini, num);
    }
    return dp[row][prevcol] = mini;
}

int solveT(int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = INT_MAX;

        for (int j = 0; j < n; j++)
        {
            if (j == i)
                continue;
            dp[0][i] = min(dp[0][i], grid[0][j]);
        }
    }

    // row iteration
    for (int i = 1; i < n; i++)
    {
        // column iteration
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = INT_MAX;

            // For each cell of the column, consider the minimum of all the values of the previous row.
            for (int prev = 0; prev < n; prev++)
            {
                if (prev == j)
                    continue;

                int num = grid[i][prev] + dp[i - 1][prev];

                dp[i][j] = min(dp[i][j], num);
            }
        }
    }
    return dp[n - 1][n];
}

// Space Optimization
int solveT(int n, vector<vector<int>> &grid)
{
    vector<int> prevv(n + 1, -1);

    for (int i = 0; i <= n; i++)
    {
        prevv[i] = INT_MAX;

        for (int j = 0; j < n; j++)
        {
            if (j == i)
                continue;
            prevv[i] = min(prevv[i], grid[0][j]);
        }
    }

    // row iteration
    for (int i = 1; i < n; i++)
    {
        vector<int> curr(n + 1, INT_MAX);
        // column iteration
        for (int j = 0; j <= n; j++)
        {
            // For each cell of the column, consider the minimum of all the values of the previous row.
            for (int prev = 0; prev < n; prev++)
            {
                if (prev == j)
                    continue;

                int num = grid[i][prev] + prevv[prev];

                curr[j] = min(curr[j], num);
            }
        }
        prevv = curr;
    }
    return prevv[n];
}

int main()
{
    vector<vector<int>> arr;
    int n;
    cout << "Enter the value of n(n*n) : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            temp.push_back(a);
        }
        arr.push_back(temp);
    }

    cout << endl
         << "Minimum Path sum : " << solveT(n, arr) << endl;
}