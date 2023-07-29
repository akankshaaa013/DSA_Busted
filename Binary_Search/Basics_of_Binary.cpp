#include <bits/stdc++.h>
using namespace std;

// Finds lower bound of an array.
int lowerBound(vector<int> arr, int n, int x)
{

    int low = 0;
    int high = n - 1;

    int ans = n;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x)
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



// Binary Search Implemetation using Recursive method.
int Binary_search(vector<int> &nums, int low, int high, int target)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (nums[mid] == target)
        return mid;
    else if (nums[mid] > target)
        return Binary_search(nums, low, mid - 1, target);
    else
        return Binary_search(nums, mid + 1, high, target);
}

// Binary Search Implemetation using Iterative loop method.
int Iterative_Binary_search(vector<int> &nums, int target)
{
    int high = nums.size() - 1;
    int low = 0;

    int mid = low + (high - low) / 2;

    while (low <= high)
    {

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;

        mid = low + (high - low) / 2;
    }

    return -1;
}

int main()
{

    int n;
    vector<int> arr;
    cout << "Enter the size of the array : ";
    cin >> n;
    cout << "Enter the array elements(in a sorted fashion) : ";
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    int target;
    cout << "Enter the target : ";
    cin >> target;

    int ans = Binary_search(arr, 0, n - 1, target);

    if (ans == -1)
        cout << "Element Not Found :(" << endl;
    else
        cout << "Element is present at index " << ans << " :)" << endl;
}