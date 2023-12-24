#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, string &s, string &t, vector<vector<double>> &dp)
{
    if (j == 0)
        return 1;
    if (i == 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i - 1] == t[j - 1])
        return dp[i][j] = solve(i - 1, j - 1, s, t, dp) + solve(i - 1, j, s, t, dp);
    else
        return dp[i][j] = solve(i - 1, j, s, t, dp);
}

int solveT(int n, int m, string &s, string &t, vector<vector<double>> &dp)
{
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int j = 1; j <= m; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return (int)dp[n][m];
}

int solveSO(int n, int m, string &s, string &t)
{
    vector<double> prev(m + 1, 0), curr(m + 1, 0);

    prev[0] = 1;
    // curr[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            if (s[i - 1] == t[j - 1])
                prev[j] = prev[j - 1] + prev[j];
            else
                prev[j] = prev[j];
        }
        // prev = curr;
    }

    return (int)prev[m];
}

int numDistinct(string s, string t)
{

    int n = s.length();
    int m = t.length();

    vector<vector<double>> dp(n + 1, vector<double>(m + 1, -1));

    return solveT(n, m, s, t, dp);
}

int main()
{
    string s1, s2;

    cout << "Enter the string s1 & s2 : ";
    cin >> s1 >> s2;

    cout << endl
         << "The Total no. of distinct subsequences are : " << numDistinct(s1, s2) << endl;
}