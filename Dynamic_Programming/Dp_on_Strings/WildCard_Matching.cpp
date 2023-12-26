#include <bits/stdc++.h>
using namespace std;

bool solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return true;

    if (i == 0 && j > 0)
        return false;

    if (j == 0 && i > 0)
    {
        for (int k = 0; k < i; k++)
            if (s1[k] != '*')
                return false;

        return true;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
    {
        return dp[i][j] = solve(i - 1, j - 1, s1, s2, dp);
    }

    if (s1[i - 1] == '*')
    {
        return dp[i][j] = solve(i - 1, j, s1, s2, dp) || solve(i, j - 1, s1, s2, dp);
    }

    return dp[i][j] = false;
}

int solveT(int m, int n, string &s1, string &s2, vector<vector<int>> &dp)
{
    dp[0][0] = 1;

    for (int j = 1; j <= n; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= m; i++)
    {
        bool flag = true;
        for (int k = 0; k < i; k++)
            if (s1[k] != '*')
            {
                flag = false;
                break;
            }
        dp[i][0] = flag;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (s1[i - 1] == '*')
            {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }

            else
                dp[i][j] = false;
        }
    }
    return dp[m][n];
}

int solveSO(int m, int n, string &s1, string &s2)
{
    vector<int> prev(n + 1, 0), curr(n + 1, 0);

    prev[0] = 1;

    for (int j = 1; j <= n; j++)
        prev[j] = 0;

    for (int i = 1; i <= m; i++)
    {
        bool flag = true;

        for (int k = 0; k < i; k++)
            if (s1[k] != '*')
            {
                flag = false;
                break;
            }
        curr[0] = flag;

        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
            {
                curr[j] = prev[j - 1];
            }
            else if (s1[i - 1] == '*')
            {
                curr[j] = prev[j] || curr[j - 1];
            }

            else
                curr[j] = false;
        }
        prev = curr;
    }
    return prev[n];
}

bool WildcardMatching(string &s1, string &s2)
{
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    return solve(n - 1, m - 1, s1, s2, dp);
}

int main()
{
    string s1, s2;

    // s1 -> '?' or '*'

    cout << "Enter the string s1 & s2 : ";
    cin >> s1 >> s2;

    if (WildcardMatching(s1, s2) == true)
        cout << "String matches!";
    else
        cout << "String doesn't matches!";
}