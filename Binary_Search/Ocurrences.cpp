#include <bits/stdc++.h>
using namespace std;

pair<int, int> FirstAndLastOcurences(vector<int> &nums, int target)
{
    int n = nums.size();

    if (n == 0)
    {
        return {-1, -1};
    }

    int first = -1;
    int last = -1;

    // Finding Lower Bound

    int low = 0;
    int high = nums.size() - 1;

    int mid = low + (high - low) / 2;

    while (low <= high)
    {

        if (nums[mid] >= target)
        {
            first = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        mid = low + (high - low) / 2;
    }

    if (first == -1 || first == n || nums[first] != target)
    {
        return {-1, -1};
    }

    // Implementing Upper Bound.

    last = (upper_bound(nums.begin(), nums.end(), target) - nums.begin()) - 1;

    return {first, last};
}

int NumberOfOccurences(vector<int> &nums, int target)
{
    pair<int, int> ans = FirstAndLastOcurences(nums, target);

    if (ans.first == -1)
        return 0;
    return ans.second - ans.first + 1;
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

    pair<int, int> ans = FirstAndLastOcurences(arr, target);

    if (ans.first != -1)
    {
        cout << "First Occurence Index : " << ans.first << endl;
        cout << "Last Occurence Index : " << ans.second << endl;
        cout << "Number of Occurences is : " << (ans.second - ans.first + 1) << endl;
    }
    else
    {
        cout << "Element not present in the array :|" << endl;
    }
}