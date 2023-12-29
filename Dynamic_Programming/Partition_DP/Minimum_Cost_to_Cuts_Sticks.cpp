#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = 1e9;

    for (int k = i; k <= j; k++)
    {
        int cut = (cuts[j + 1] - cuts[i - 1]) + f(i, k - 1, cuts, dp) + f(k + 1, j, cuts, dp);
        mini = min(mini, cut);
    }
    return dp[i][j] = mini;
}

int fT(int x, vector<int> &cuts, vector<vector<int>> &dp)
{
    for (int i = x; i >= 1; i--)
    {
        for (int j = 1; j <= x; j++)
        {
            if (i > j)
                continue;

            int mini = 1e9;

            for (int k = i; k <= j; k++)
            {
                int cut = (cuts[j + 1] - cuts[i - 1]) + dp[i][k - 1] + dp[k + 1][j];
                mini = min(mini, cut);
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][x];
}

int minCost(int n, vector<int> &cuts)
{

    int x = cuts.size();

    cuts.push_back(0);

    cuts.push_back(n);

    vector<vector<int>> dp(x + 2, vector<int>(x + 2, -1));

    sort(cuts.begin(), cuts.end());

    return f(1, x, cuts, dp);
    // return fT(n, x, cuts, dp);
}

int main()
{
    vector<int> v;
    int n, len;
    cout << "Enter the size of the rod & no. of cuts respectively : ";
    cin >> len >> n;

    cout << "Enter the cuts position : ";
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    cout << "Minimum cost to cut the rod is : " << minCost(len, v) << endl;
}