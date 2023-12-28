#include <bits/stdc++.h>
using namespace std;

void printDP(vector<vector<int>> &dp)
{
    cout << endl;
    for (auto it : dp)
    {
        for (auto i : it)
        {
            cout << i << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

int solve(int idx, int prev_idx, vector<int> &arr, int n, vector<vector<int>> &dp)
{
    if (idx == n)
        return 0;

    if (dp[idx][prev_idx + 1] != -1)
        return dp[idx][prev_idx + 1];

    int maxi = 0;

    maxi = 0 + solve(idx + 1, prev_idx, arr, n, dp);

    if (prev_idx == -1 || arr[idx] > arr[prev_idx])
    {
        maxi = max(maxi, 1 + solve(idx + 1, idx, arr, n, dp));
    }

    return dp[idx][prev_idx + 1] = maxi;
}

int solveT(vector<int> &arr, int n, vector<vector<int>> &dp)
{
    //* dp[*][prev_idx + 1] because of coordinate shift.
    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int prev_idx = idx - 1; prev_idx >= -1; prev_idx--)
        {
            int maxi = 0;

            maxi = 0 + dp[idx + 1][prev_idx + 1];

            if (prev_idx == -1 || arr[idx] > arr[prev_idx])
            {
                maxi = max(maxi, 1 + dp[idx + 1][idx + 1]);
            }

            dp[idx][prev_idx + 1] = maxi;
        }
    }

    printDP(dp);

    return dp[0][-1 + 1];
}

int solveSO(vector<int> &arr, int n)
{
    //* dp[*][prev_idx + 1] because of coordinate shift.
    vector<int> ahead(n + 1, 0), curr(n + 1, 0);

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int prev_idx = idx - 1; prev_idx >= -1; prev_idx--)
        {
            int maxi = 0;

            maxi = 0 + ahead[prev_idx + 1];

            if (prev_idx == -1 || arr[idx] > arr[prev_idx])
            {
                maxi = max(maxi, 1 + ahead[idx + 1]);
            }

            curr[prev_idx + 1] = maxi;
        }
        ahead = curr;
    }

    return ahead[-1 + 1];
}

int solveAlt(vector<int> &arr, int n)
{
    vector<int> dp(n, 1), hash(n);

    for (int i = 0; i < n; i++)
        hash[i] = i;

    int maxi = 1;
    int max_idx = 0;

    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i] && dp[i] < 1 + dp[prev])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            max_idx = i;
        }
    }

    // cout << endl << max_idx << endl;

    for (auto it : dp)
        cout << it << "  ";

    cout<<endl;

    // for (auto it : arr)
    //     cout << it << "  ";

    vector<int> ans;

    while (hash[max_idx] != max_idx)
    {
        ans.push_back(arr[max_idx]);
        max_idx = hash[max_idx];
    }
    ans.push_back(arr[max_idx]);

    reverse(ans.begin(), ans.end());

    for (auto it : ans)
        cout << it << "  ";

    return maxi;
}

int LIS(vector<int> &arr, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    int ans = solveAlt(arr, n);

    return ans;
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

    cout << endl
         << "Length of the Longest Increasing subsequence is : " << LIS(v, n);
}