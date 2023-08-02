#include <bits/stdc++.h>
using namespace std;

int maxElement(vector<int> &arr)
{
    int max = INT_MIN;

    for (auto i : arr)
    {
        if (i > max)
        {
            max = i;
        }
    }
    return max;
}

long long Calculate(vector<int> &nums, int k)
{
    long long NumberOfHours = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        NumberOfHours += (nums[i] % k == 0) ? nums[i] / k : (nums[i] / k) + 1;
    }
    return NumberOfHours;
}

int MinimumBananasKokoCanEatPerHr(vector<int> &arr, int h)
{
    long long low = 1;
    long long high = maxElement(arr);
    long long ans = 0;

    while (low <= high)
    {
        // No. of bananas per hour
        long long mid = low + (high - low) / 2;

        long long Time1 = Calculate(arr, mid);

        if (Time1 <= h)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    vector<int> arr;
    cout << "Enter the no. of piles : ";
    cin >> n;
    cout << "Enter the Stock of banana piles : ";
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    int target;
    cout << "Enter the Hours : ";
    cin >> target;

    cout << "Minimum Bananas Koko Can Eat per Hours is : " << MinimumBananasKokoCanEatPerHr(arr, target);
}