#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(vector<int> arr, int n)
{
    long long sum = 0;
    long long maxSum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum > maxSum)
            maxSum = sum;

        if (sum < 0)
            sum = 0;
    }
    return maxSum;
}

int main()
{
    vector<int> v;
    int n;
    cout << "Enter the size of vector : ";
    cin >> n;

    cout << "Enter the vector elements : ";
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    long long ans = maxSubarraySum(v, n);
    cout << ans;
}