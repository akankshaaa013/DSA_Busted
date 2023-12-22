#include <bits/stdc++.h>
using namespace std;

// Memoization
// T.C -> O(n * m)
// S.C -> O(n + m)[stack space] + O(n * m)[dp array]
int solve(int idx1, int idx2, string &s, string &t, vector<vector<int>> &dp)
{
    if (idx1 == 0 || idx2 == 0)
        return 0;

    if (dp[idx1][idx2] != -1)
        return dp[idx1][idx2];

    // Since the string follows 0-based indexing so the comparison needs to be done accordingly.
    if (s[idx1 - 1] == t[idx2 - 1])
        return dp[idx1][idx2] = 1 + solve(idx1 - 1, idx2 - 1, s, t, dp);

    else
        return dp[idx1][idx2] = 0 + max(solve(idx1 - 1, idx2, s, t, dp), solve(idx1, idx2 - 1, s, t, dp));
}

// Tabulation
// T.C -> O(n * m)
// S.C -> O(n * m)[dp array]
int solveT(int n, int m, string &s, string &t, vector<vector<int>> &dp)
{
    // for(int i = 0; i <= n; i++)     dp[i][0] = 0;

    // for(int j = 0; j <= m; j++)     dp[0][j] = 0;

    for (int idx1 = 1; idx1 <= n; idx1++)
    {
        for (int idx2 = 1; idx2 <= m; idx2++)
        {
            if (s[idx1 - 1] == t[idx2 - 1])
                dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];

            else
                dp[idx1][idx2] = 0 + max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
        }
    }

    return dp[n][m];
}

// Space Optimization
// T.C -> O(n * m)
// S.C -> O(m + m)[prev & curr array]
int solveSO(int n, int m, string &s, string &t)
{
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for (int idx1 = 1; idx1 <= n; idx1++)
    {
        for (int idx2 = 1; idx2 <= m; idx2++)
        {
            if (s[idx1 - 1] == t[idx2 - 1])
                curr[idx2] = 1 + prev[idx2 - 1];

            else
                curr[idx2] = 0 + max(prev[idx2], curr[idx2 - 1]);
        }
        prev = curr;
    }
    return prev[m];
}

int longestCommonSubsequence(string s, string t)
{

    int n = s.length();
    int m = t.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    return solveSO(n, m, s, t);
}

string printLCS(string &s1, string &s2)
{

    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int len = solveT(n, m, s1, s2, dp);

    string ans = "";
    for (int i = 0; i < len; i++)
        ans += '$';

    int idx = len - 1;

    int i = n;
    int j = m;

    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans[idx] = s1[i - 1];
            idx--;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    return ans;
}

int main()
{
    string s1, s2;

    cout << "Enter the string s1 & s2 : ";
    cin >> s1 >> s2;

    cout << endl
         << "The Longest Common Subsequence is : " << printLCS(s1, s2) << endl;
}
