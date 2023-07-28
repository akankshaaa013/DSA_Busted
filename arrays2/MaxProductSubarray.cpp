#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums)
{
    int prefix = 1;
    int n = nums.size();
    int suffix = 1;
    int maxi = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {

        prefix = (prefix ? prefix : 1) * nums[i];
        suffix = (suffix ? suffix : 1) * nums[n - i - 1];

        maxi = max(maxi, max(prefix, suffix));
    }

    return maxi;
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

    cout<<"Maximum product Subarray is : "<<maxProduct(arr)<<endl;
}