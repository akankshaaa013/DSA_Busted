#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int maxi = -1e9;

    for (int k = i; k <= j; k++)
    {
        int cost = nums[i - 1] * nums[k] * nums[j + 1] + f(i, k - 1, nums, dp) + f(k + 1, j, nums, dp);

        maxi = max(maxi, cost);
    }
    return dp[i][j] = maxi;
}

int fT(int n, vector<int> &nums, vector<vector<int>> &dp)
{
    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j <= n; j++)
        {
            int maxi = -1e9;

            for (int k = i; k <= j; k++)
            {
                int cost = nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j];
                maxi = max(maxi, cost);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[1][n];
}

int maxCoins(vector<int> &nums)
{

    int n = nums.size();

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    nums.push_back(1);

    nums.insert(nums.begin(), 1);

    return fT(n, nums, dp);
}

int main()
{
    vector<int> v;
    int n;
    cout << "Enter the size of array : ";
    cin >> n;

    cout << "Enter the array elements : ";
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    cout << "Maximum coins that can be collected are : " << maxCoins(v) << endl;
}