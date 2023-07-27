#include <bits/stdc++.h>
using namespace std;

//* BETTER APPROACH
//* fourSum() function accepts a vector and target sum and returns the list of all unique triplets whose sum is equivalent
//* to target sum.
//* Time Complexity : O(n^3)
//* Space Complexity : O(n)
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    set<vector<int>> st;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            set<int> hash;
            for (int k = j + 1; k < nums.size(); k++)
            {

                int last = -(-target + nums[i] + nums[j] + nums[k]);
                if (hash.find(last) != hash.end())
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], last};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hash.insert(nums[k]);
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}



//* OPTIMIZED APPROACH
//* TIME COMPLEXITY : O(nlogn) + O(n^3).
//* SPACE COMPLEXITY : O(1).
vector<vector<int>> fourSum2(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {

        if (i > 0 && nums[i - 1] == nums[i])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && nums[j - 1] == nums[j])
                continue;

            int x = j + 1;
            int y = n - 1;
            while (x < y)
            {
                long long int sum = nums[i] + nums[j];
                sum += nums[x];
                sum += nums[y];
                if (sum > target)
                {
                    y--;
                }
                else if (sum < target)
                {
                    x++;
                }
                else
                {
                    vector<int> temp = {nums[i], nums[j], nums[x], nums[y]};

                    ans.push_back(temp);
                    x++;
                    y--;

                    while (nums[x - 1] == nums[x] && x < y)
                        x++;
                    while (nums[y + 1] == nums[y] && x < y)
                        y--;
                }
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

    vector<vector<int>> ans = fourSum2(v, k);

    cout << "Quadraplets are : \n";
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << "  ";
        }
        cout << endl;
    }
}