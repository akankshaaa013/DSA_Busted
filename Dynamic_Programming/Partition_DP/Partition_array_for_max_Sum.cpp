#include <bits/stdc++.h>
using namespace std;

int f(int idx, vector<int> &arr, int k, vector<int> &dp, int n)
{
    if (idx == n)
        return 0;

    int len = 0, maxi = INT_MIN;

    int ans = INT_MIN;

    if (dp[idx] != -1)
        return dp[idx];

    for (int j = idx; j < min(idx + k, n); j++)
    {
        maxi = max(maxi, arr[j]);
        len++;

        int maxSum = (maxi * len) + f(j + 1, arr, k, dp, n);
        ans = max(ans, maxSum);
    }
    return dp[idx] = ans;
}

int fT(vector<int> &arr, int k, vector<int> &dp, int n)
{

    for (int idx = n - 1; idx >= 0; idx--)
    {
        int len = 0, maxi = INT_MIN;

        int ans = INT_MIN;

        for (int j = idx; j < min(idx + k, n); j++)
        {
            maxi = max(maxi, arr[j]);
            len++;

            int maxSum = (maxi * len) + dp[j + 1];
            ans = max(ans, maxSum);
        }
        dp[idx] = ans;
    }

    cout << endl;
    for(auto it : dp)
    {
        cout << it << "  ";
    }
    cout << endl;
    
    return dp[0];
}

int maxSumAfterPartitioning(vector<int> &arr, int k)
{

    int n = arr.size();
    vector<int> dp(n + 1, 0);

    return fT(arr, k, dp, n);
}

int main()
{
    vector<int> v;
    int n, k;
    cout << "Enter the size of array & value of k respectively: ";
    cin >> n >> k;

    cout << "Enter the array elements : ";
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    cout << "Maximum sum after partitioning the array such that each partition contains atmost k elements is : " << maxSumAfterPartitioning(v, k) << endl;
}