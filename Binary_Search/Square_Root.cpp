#include <bits/stdc++.h>
using namespace std;

// Returns 1 if pow(mid,n) == m
// Returns 0 if pow(mid,n) < m
// Returns 2 if pow(mid,n) > m
int func(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;

        if (ans > m)
        {
            return 2;
        }
    }
    if (ans == m)
        return 1;
    return 0;
}

int NthRootOfaIntegerM(int m, int n)
{

    int low = 1;
    int high = m;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (func(mid, n, m) == 1)
            return mid;
        else if (func(mid, n, m) == 2)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int findSqaureRootUsingBinarySearch(int n)
{
    int low = 1;
    int high = n;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if ((mid * mid) <= n)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}

int main()
{
    int m, n;

    cout << "Enter the value of m : ";
    cin >> m;
    cout << "Enter the value of n : ";
    cin >> n;

    // cout << "Integer portion of square root of 'n' is : " << findSqaureRootUsingBinarySearch(n) << endl;

    cout << "Nth root of m is : " << NthRootOfaIntegerM(m, n);
}