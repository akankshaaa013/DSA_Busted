#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    if (i == 0)
        return j;

    if (j == 0)
        return i;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i - 1] == t[j - 1])
        return dp[i][j] = 0 + solve(i - 1, j - 1, s, t, dp);

    int insert = 1 + solve(i, j - 1, s, t, dp);
    int del = 1 + solve(i - 1, j, s, t, dp);
    int replace = 1 + solve(i - 1, j - 1, s, t, dp);

    return dp[i][j] = min(insert, min(del, replace));
}

int solveT(int n, int m, string &s, string &t, vector<vector<int>> &dp)
{
    // i -> row     j -> col

    // Min no. of operation to convert an string into an empty string. (i -> deletion)
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;

    // Min no. of operation to convert an empty string into a string of length j. (j -> insertions)
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

    // dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 0 + dp[i - 1][j - 1];
            else
            {
                int insert = 1 + dp[i][j - 1];
                int del = 1 + dp[i - 1][j];
                int replace = 1 + dp[i - 1][j - 1];

                dp[i][j] = min(insert, min(del, replace));
            }
        }
    }
    return dp[n][m];
}

int solveSO(int n, int m, string &s, string &t)
{
    // i -> row     j -> col

    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    // Min no. of operation to convert an empty string into a string of length j. (j -> insertions)
    for (int j = 0; j <= m; j++)
        prev[j] = j;

    for (int i = 1; i <= n; i++)
    {
        curr[0] = i;
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                curr[j] = 0 + prev[j - 1];
            else
            {
                int insert = 1 + curr[j - 1];
                int del = 1 + prev[j];
                int replace = 1 + prev[j - 1];

                curr[j] = min(insert, min(del, replace));
            }
        }
        prev = curr;
    }
    return prev[m];
}

int minDistance(string word1, string word2)
{

    int n = word1.size();
    int m = word2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    return solveSO(n, m, word1, word2);
}

int main()
{
    string s1, s2;

    cout << "Enter the string s1 & s2 : ";
    cin >> s1 >> s2;

    cout << endl
         << "Minimum no. of operations to convert string s1 to strig s2 is : " << minDistance(s1, s2) << endl;
}