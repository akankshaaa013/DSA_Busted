#include <bits/stdc++.h>
using namespace std;

// Overall time complexity is : O(n+k+n-k) = O(2n).
// Overall space complexity is : O(1).
void rotate_by_K(vector<int> &arr, int n, int K)
{
    // T.C : O(n)
    reverse(arr.begin(), arr.end());

    // T.C : O(k)
    reverse(arr.begin() + n - K, arr.end());

    // T.C : O(n-k)
    reverse(arr.begin(), arr.end() - K);
}

// Overall time complexity is : O(n+k).
// Overall space complexity is : O(k).
void rotate_by_K2(vector<int> &arr, int n, int k)
{
    k %= n;

    vector<int> temp(k);

    // T.C : O(k)
    for (int i = 0; i < k; i++)
    {
        temp.push_back(arr[i]);
    }

    // T.C : O(n-k)
    for (int i = k; i < n; i++)
    {
        arr[i - k] = arr[i];
    }

    // T.C : O(k)
    for (int i = n - k; i < n; i++)
    {
        arr[i] = temp[i - (n - k)];
    }
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

    int k;
    cout << "Enter the value of K : ";
    cin >> k;

    rotate_by_K(arr, n, k);

    cout << "Rotated Array is : ";

    for (auto it : arr)
    {
        cout << it << "  ";
    }
}