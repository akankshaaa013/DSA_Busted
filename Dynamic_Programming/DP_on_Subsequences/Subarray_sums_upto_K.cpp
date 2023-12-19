#include <bits/stdc++.h>
using namespace std;

bool solve(int idx, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;

    if (idx == 0)
        return (arr[idx] == target);

    if (dp[idx][target] != -1)
        return dp[idx][target];

    bool notTake = solve(idx - 1, target, arr, dp);

    bool take = false;

    if (arr[idx] <= target)
        take = solve(idx - 1, target - arr[idx], arr, dp);

    return dp[idx][target] = (take | notTake);
}

bool solveT(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    dp[0][arr[0]] = true;

    for (int idx = 1; idx < n; idx++)
    {
        for (int target = 1; target < k + 1; target++)
        {
            bool nottake = dp[idx - 1][target];
            bool take = false;

            if (target >= arr[idx])
            {
                take = dp[idx - 1][target - arr[idx]];
            }
            dp[idx][target] = take | nottake;
        }
    }
    return dp[n - 1][k];
}

bool solveSO(int n, int k, vector<int> &arr)
{

    vector<bool> prev(k + 1, false);

    prev[0] = true;

    prev[arr[0]] = true;

    for (int idx = 1; idx < n; idx++)
    {
        vector<bool> curr(k + 1, false);
        curr[0] = true;

        for (int target = 1; target < k + 1; target++)
        {
            bool nottake = prev[target];
            bool take = false;

            if (target >= arr[idx])
            {
                take = prev[target - arr[idx]];
            }
            curr[target] = take | nottake;
        }
        prev = curr;
    }
    return prev[k];
}

int main()
{
    vector<int> v;
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    cout << "Enter the array elements : ";

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int target;
    cout << "Enter the target sum : ";
    cin >> target;

    if (solveSO(n, target, v) == true)
        cout << "Subset sum is possible";
    else
        cout << "Subset sum is not possible";
}