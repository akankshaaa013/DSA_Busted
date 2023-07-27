#include <bits/stdc++.h>
using namespace std;

//* BETTER APPROACH
//* Triplet() function accepts a vector and target sum and returns the list of all unique triplets whose sum is equivalent
//* to target sum.
//* Time Complexity : O(n^2)
//* Space Complexity : O(n)
vector<vector<int>> triplet(int n, vector<int> &arr, int k)
{
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        set<int> hashSet;
        for (int j = i + 1; j < n; j++)
        {
            int third = -(-k + arr[i] + arr[j]);

            if (hashSet.find(third) != hashSet.end())
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end()); // Only 3 elemets are sorted. So the time complexity of sort() is equivalent to constant.
                st.insert(temp);
            }
            hashSet.insert(arr[j]);
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());

    return ans;
}

//* OPTIMIZED APPROACH
//* TIME COMPLEXITY : O(nlogn) + O(n^2).
//* SPACE COMPLEXITY : O(1).
vector<vector<int>> threeSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (unsigned int i = 0; i < nums.size(); i++)
    {

        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int j = i + 1;
        int k = nums.size() - 1;

        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];

            if (sum > target)
            {
                k--;
            }
            else if (sum < target)
            {
                j++;
            }
            else
            {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);

                j++;
                k--;

                while (nums[j] == nums[j - 1] && j < k)
                    j++;
                while (nums[k] == nums[k + 1] && j < k)
                    k--;
            }
        }
    }

    return ans;
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
    int k;
    cout << "Enter the Target sum : ";
    cin >> k;

    vector<vector<int>> ans = threeSum(v, k);

    cout << "Triplet Sets are : \n";
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << "  ";
        }
        cout << endl;
    }
}