#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int i, int j, vector<vector<int>> &dpPalindrome)
{
    if (dpPalindrome[i][j] != -1)
        return dpPalindrome[i][j];

    while (i < j)
    {
        if (s[i] != s[j])
            return dpPalindrome[i][j] = false;

        i++;
        j--;
    }

    return dpPalindrome[i][j] = true;
}

int f(int idx, string &s, int n, vector<int> &dp, vector<vector<int>> &dpPalindrome)
{
    if (idx == n)
        return 0;

    if (dp[idx] != -1)
        return dp[idx];

    int minCost = INT_MAX;

    for (int j = idx; j < n; j++)
    {
        int cost = 0;
        // string is from idx....j
        
        if (isPalindrome(s, idx, j, dpPalindrome))
        {
            cost = 1 + f(j + 1, s, n, dp, dpPalindrome);
            minCost = min(minCost, cost);
        }
    }
    return dp[idx] = minCost;
}

int f(string &s, int n, vector<int> &dp, vector<vector<int>> &dpPalindrome)
{
    for (int idx = n - 1; idx >= 0; idx--)
    {
        int minCost = INT_MAX;

        for (int j = idx; j < n; j++)
        {
            int cost = 0;
            // string is idx....j
            if (isPalindrome(s, idx, j, dpPalindrome))
            {
                cost = 1 + dp[j + 1];
                minCost = min(minCost, cost);
            }
        }
        dp[idx] = minCost;
    }
    return dp[0];
}

int minCut(string s)
{

    int n = s.size();
    vector<int> dp(n + 1, 0);

    vector<vector<int>> dpPalindrome(n + 1, vector<int>(n + 1, -1));

    // Since the partition is done at the end too, So we return the answer by subracting 1.
    return f(s, n, dp, dpPalindrome) - 1;
}

int main()
{
    string s1;

    cout << "Enter the string s : ";
    cin >> s1;

    cout << "Minimum no. of partitions such that all the partitions have palindrome substring are : " << minCut(s1);
}