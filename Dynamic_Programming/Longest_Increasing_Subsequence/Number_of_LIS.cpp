#include <bits/stdc++.h>
using namespace std;

int solveAlt(vector<int> &arr, int n)
{
    vector<int> dp(n, 1), ways(n, 1);

    int maxi = 1;

    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i] && dp[i] < 1 + dp[prev])
            {
                dp[i] = 1 + dp[prev];
                ways[i] = ways[prev];
            }
            else if(arr[prev] < arr[i] && dp[i] == 1 + dp[prev])
            {
                ways[i] += ways[prev];
            }
        }

        if (dp[i] > maxi)
        {
            maxi = dp[i];
        }
    }

    cout<<endl;

    for (auto it : dp)
        cout << it << "  ";

    cout<<endl;

    for (auto it : ways)
        cout << it << "  ";

    cout<<endl;

    int cnt = 0;

    for(int i = 0; i < n; i++)
    {
        if(dp[i] == maxi)
        {
            cnt = cnt + ways[i];
        }
    }

    return cnt;
}

int LIS(vector<int> &arr, int n)
{
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
         << "Number of the Longest Increasing subsequence is : " << LIS(v, n);
}