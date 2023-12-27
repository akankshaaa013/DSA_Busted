#include <bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int> &nums)
{

    sort(nums.begin(), nums.end());

    int n = nums.size();

    vector<int> dp(n, 1), hash(n);

    for (int i = 0; i < n; i++)
        hash[i] = i;

    int idx = 0, maxi = 1;

    for (int i = 1; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (nums[i] % nums[prev] == 0 && dp[i] < dp[prev] + 1)
            {
                dp[i] = dp[prev] + 1;
                hash[i] = prev;
            }
        }
        // maxi -> length of longest divisible subset
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            idx = i;
        }
    }

    // for (auto it : hash)
    // cout << it << "  ";

    // cout<<endl;

    // for (auto it : dp)
    // cout << it << "  ";

    vector<int> ans;

    while (hash[idx] != idx)
    {
        ans.push_back(nums[idx]);
        idx = hash[idx];
    }

    ans.push_back(nums[idx]);

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

    vector<int> ans = largestDivisibleSubset(v);

    reverse(ans.begin(), ans.end());

    cout << endl;
    for (auto it : ans)
    {
        cout << it << "   ";
    }
    cout << endl;
}