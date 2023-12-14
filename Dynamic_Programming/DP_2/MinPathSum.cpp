#include<bits/stdc++.h>
using namespace std;

int solve(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(row == 0 && col == 0) return grid[0][0];

        if(row < 0 || col < 0) return 100000;

        if(dp[row][col] != -1) return dp[row][col];

        int top = grid[row][col] + solve(row-1, col, grid, dp);
        int left = grid[row][col] + solve(row, col-1, grid, dp);

        return dp[row][col] = min(top, left);
    }

    int solveT(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        for(int i = 0; i <= row; i++)
        {
            for(int j = 0; j <= col; j++)
            {
                if(i == 0 && j == 0) dp[i][j] = grid[i][j];
                else 
                {
                    int left = INT_MAX;
                    int top = INT_MAX;

                    if(i > 0) top = grid[i][j] + dp[i-1][j];
                    if(j > 0) left = grid[i][j] + dp[i][j-1];

                    dp[i][j] = min(top, left);
                }
            }
        }
        return dp[row][col];
    }

    int solveSO(int row, int col, vector<vector<int>>& grid)
    {
        vector<int> prev(col + 1, 0);

        for(int i = 0; i <= row; i++)
        {
            vector<int> curr(col + 1, 0);

            for(int j = 0; j <= col; j++)
            {
                if(i == 0 && j == 0) curr[j] = grid[0][0];
                else
                {
                    int top = INT_MAX, left = INT_MAX;

                    if(i > 0) top = grid[i][j] + prev[j];

                    if(j > 0) left = grid[i][j] + curr[j - 1];

                    curr[j] = min(top, left);
                }
            }
            prev = curr;
        }
        return prev[col];
    }

int main()
{
    vector<vector<int>> arr;
    int m, n;
    cout << "Enter the rows and cols : ";
    cin >> m >> n;

    for (int i = 0; i < m; i++)
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

    cout<< endl << "Minimum Path sum : " << solveSO(m-1, n-1, arr) << endl;

}