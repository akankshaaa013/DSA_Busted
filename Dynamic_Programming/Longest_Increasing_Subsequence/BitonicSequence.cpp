#include <bits/stdc++.h>
using namespace std;

int largestBitonic(vector<int> &nums, int n)
{
    vector<int> dp1(n, 1);

    // Forward Increasing.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j] && dp1[i] < dp1[j] + 1)
            {
                dp1[i] = dp1[j] + 1;
            }
        }
    }

    vector<int> dp2(n, 1);
    int maxi = 1;

    // Backward increasing.
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (nums[i] > nums[j] && dp2[i] < dp2[j] + 1)
            {
                dp2[i] = dp2[j] + 1;
            }
        }

        // Computing the Largest Bitonic Subsequence.
        maxi = max(maxi, dp2[i] + dp1[i] - 1);
    }

    return maxi;
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

    cout << "Length of the largest Bitonic subsequence is : " << largestBitonic(v, n) << endl;
}