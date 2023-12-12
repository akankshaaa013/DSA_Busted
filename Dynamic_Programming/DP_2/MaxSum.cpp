#include <bits/stdc++.h>
using namespace std;

// Constraint : From every row, only 1 element/value can be picked.

int solve(int day, int prevVal, vector<vector<int>> &points, vector<vector<int>> &dp)
{

    if (day == 0)
    {
        int maxi = -1;
        for (int task = 0; task < 3; task++)
        {
            if (task != prevVal)
                maxi = max(maxi, points[0][task]);
        }
        return maxi;
    }

    if (dp[day][prevVal] != -1)
        return dp[day][prevVal];

    int maxi = -1;
    for (int task = 0; task < 3; task++)
    {
        if (task != prevVal)
        {
            int pnts = points[day][task] + solve(day - 1, task, points, dp);
            maxi = max(maxi, pnts);
        }
    }

    return dp[day][prevVal] = maxi;
}

int solveT(int n, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }

    return dp[n - 1][3];
}

int solveSO(int n, vector<vector<int>> &points)
{
    vector<int> prev(4, 0);

    prev[0] = max(points[0][1], points[0][2]);

    prev[1] = max(points[0][0], points[0][2]);

    prev[2] = max(points[0][0], points[0][1]);

    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++)
        {
            temp[last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    temp[last] = max(temp[last], points[day][task] + prev[task]);
                }
            }
        }
        prev = temp;
    }

    return prev[3];
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
        for (int j = 0; j < 3; j++)
        {
            int a;
            cin >> a;
            temp.push_back(a);
        }
        arr.push_back(temp);
    }

    vector<vector<int>> dp(m, vector<int>(4, -1));

    cout << solveT(m, arr, dp);
}