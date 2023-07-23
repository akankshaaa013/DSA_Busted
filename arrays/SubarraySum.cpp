#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(2n).
// Space Complexity : O(1).
int subarraySum2(vector<int> &arr, long long k)
{

    int left = 0, right = 0;

    long long sum = arr[0];
    int maxLen = 0;
    int n = arr.size();

    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= arr[left];
            left++;
        }

        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if (right < n)
        {
            sum += arr[right];
        }
    }
    return maxLen;
}


// If using unordered map, then time complexity is : O(n*1). If max no. collisions the time complexity goes uptil O(n^2).
// If using ordered map, then the time complexity is : O(n*log n).
int subarraySum(vector<int> &arr, long long k)
{

    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }
        int rem = sum - k;
        // If the element is present in the hashmap then the iterator pointing to that element is returned.
        // Else the end iterator is returned.
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        // If the sum is not stored in the map, then store the sum along with it's index.
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}

int main()
{

    int n;
    vector<int> arr;
    cout << "Enter the size of the array : ";
    cin >> n;
    cout << "Enter the vector elements : ";
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    long long k;
    cout << "Enter the target sum : ";
    cin >> k;

    cout << "\nMaximum Length of Subarray : " << subarraySum2(arr, k);
}