#include <bits/stdc++.h>
using namespace std;

int solve(int row, int col, vector<vector<int>> &dp)
{
    if (row == 0 && col == 0)
        return 1;

    if (row < 0 || col < 0)
        return 0;

    if (dp[row][col] != -1)
        return dp[row][col];

    int top = solve(row - 1, col, dp);
    int left = solve(row, col - 1, dp);

    return dp[row][col] = top + left;
}

int solveT(int row, int col, vector<vector<int>> &dp)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else
            {
                int top = 0, left = 0;
                if (i > 0)
                    top = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];

                dp[i][j] = top + left;
            }
        }
    }
    return dp[row - 1][col - 1];
}

int solveSO(int row, int col)
{
    vector<int> prev(col, 0);

    for (int i = 0; i < row; i++)
    {
        vector<int> temp(col, 0);

        for (int j = 0; j < col; j++)
        {
            if (i == 0 && j == 0)
                temp[j] = 1;
            else
            {
                int top = 0, left = 0;
                if (i > 0)
                    top = prev[j];
                if (j > 0)
                    left = temp[j - 1];

                temp[j] = top + left;
            }
        }
        prev = temp;
    }
    return prev[col - 1];
}

int main()
{
    vector<vector<int>> arr;
    int m, n;
    cout << "Enter the rows and cols : ";
    cin >> m >> n;

    vector<vector<int>> dp(m, vector<int>(n, -1));

    cout << "Total number of unique path are : " << solveT(m, n, dp);
}