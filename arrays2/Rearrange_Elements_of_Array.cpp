#include <bits/stdc++.h>
using namespace std;

//*TIME COMPLEXITY : O(N).
//*SPACE COMPLEXITY : O(N).

vector<int> rearrangeArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 0);
    int pos = 0;
    int neg = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            ans[pos] = nums[i];
            pos += 2;
        }
        else
        {
            ans[neg] = nums[i];
            neg += 2;
        }
    }
    return ans;
}


//*TIME COMPLEXITY : O(N)+O(N/2).
//*SPACE COMPLEXITY : O(N).

vector<int> rearrangeArray1(vector<int> &nums)
{
    vector<int> pos, neg;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            pos.push_back(nums[i]);
        }
        else
        {
            neg.push_back(nums[i]);
        }
    }
    if (pos.size() > neg.size())
    {
        for (int i = 0; i < neg.size(); i++)
        {
            nums[i * 2] = pos[i];
            nums[i * 2 + 1] = neg[i];
        }

        int index = neg.size() * 2;

        for (int i = neg.size(); i < pos.size(); i++)
        {
            nums[index] = pos[i];
            index += 1;
        }
    }
    else
    {
        for (int i = 0; i < pos.size(); i++)
        {
            nums[i * 2] = neg[i];
            nums[i * 2 + 1] = pos[i];
        }

        int index = 2 * pos.size();

        for (int i = pos.size(); i < neg.size(); i++)
        {
            nums[index++] = neg[i];
        }
    }
    return nums;
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

    vector<int> ans = rearrangeArray1(v);

    cout << "Rearranged array is : ";

    for (auto it : ans)
    {
        cout << it << "   ";
    }
}