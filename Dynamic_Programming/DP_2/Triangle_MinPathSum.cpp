#include <bits/stdc++.h>
using namespace std;
/*
1
5 3
8 5 2
3 4 6 2
1 2 3 8 9

Min Path Sum -> 15
*/

int solve(int row, int col, vector<vector<int>> &dp, int n, vector<vector<int>> &triangle)
{
    if (row == n - 1)
        return triangle[n - 1][col];

    if (dp[row][col] != -1)
        return dp[row][col];

    int bottom = triangle[row][col] + solve(row + 1, col, dp, n, triangle);

    int diag = triangle[row][col] + solve(row + 1, col + 1, dp, n, triangle);

    return dp[row][col] = min(bottom, diag);
}

int solveT(vector<vector<int>> &dp, int n, vector<vector<int>> &triangle)
{
    for (int i = 0; i <= n - 1; i++)
    {
        dp[n - 1][i] = triangle[n - 1][i];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int diag = triangle[i][j] + dp[i + 1][j + 1];

            dp[i][j] = min(down, diag);
        }
    }

    return dp[0][0];
}

int solveSO(int n, vector<vector<int>> &triangle)
{
    vector<int> next(n, -1);

    for (int i = 0; i <= n - 1; i++)
    {
        next[i] = triangle[n - 1][i];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> curr(n, 0);
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + next[j];
            int diag = triangle[i][j] + next[j + 1];

            curr[j] = min(down, diag);
        }
        next = curr;
    }

    return next[0];
}

int main()
{
    vector<vector<int>> arr;
    int m;
    cout << "Enter the rows : ";
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        vector<int> temp;
        for (int j = 0; j < i + 1; j++)
        {
            int a;
            cin >> a;
            temp.push_back(a);
        }
        arr.push_back(temp);
    }

    vector<vector<int>> dp(m, vector<int>(m, -1));

    cout << endl
         << "Minimum Path sum : " << solveSO(m, arr) << endl;
}