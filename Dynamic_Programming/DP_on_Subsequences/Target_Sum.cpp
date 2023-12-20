#include <bits/stdc++.h>
using namespace std;

// Returns the no. of subsets whose sum gives the target.
int solve(int idx, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;

        if (target == 0 || arr[0] == target)
            return 1;

        return 0;
    }

    if (dp[idx][target] != -1)
        return dp[idx][target];

    int notTake = solve(idx - 1, target, arr, dp);

    int take = 0;

    if (arr[idx] <= target)
        take = solve(idx - 1, target - arr[idx], arr, dp);

    return dp[idx][target] = (take + notTake);
}


int solveT(int n, int tar, vector<int> &arr, vector<vector<int>> &dp)
{

    if (arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;

    if (arr[0] != 0 && tar >= arr[0])
        dp[0][arr[0]] = 1;

    for (int idx = 1; idx < n; idx++)
    {
        for (int target = 0; target <= tar; target++)
        {
            int notTake = dp[idx - 1][target];
            int take = 0;
            if (arr[idx] <= target)
                take = dp[idx - 1][target - arr[idx]];
            dp[idx][target] = (take + notTake);
        }
    }

    return dp[n - 1][tar];
}


int countPartitions(int n, int d, vector<int> &arr)
{
    int totSum = 0;

    for (auto it : arr)
        totSum += it;

    if (totSum - d < 0 || (totSum - d) % 2)
        return 0;

    int s2 = (totSum - d) / 2;

    vector<vector<int>> dp(n, vector<int>(s2 + 1, 0));

    return solveT(n, s2, arr, dp);
}
int findTargetSumWays(vector<int> &nums, int target)
{
    return countPartitions(nums.size(), target, nums);
}

int main()
{

    int n, target;
    cout << "Enter the value of n & target: ";
    cin >> n >> target;

    vector<int> arr;

    cout << "Enter the array elements : ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    cout << endl
         << "The number of different expressions that evaluates to target is : "<< findTargetSumWays(arr, target) << endl;
}