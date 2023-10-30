#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &nums)
{
    for (auto i : nums)
    {
        cout << i << "   ";
    }
    cout << endl;
}
vector<int> slidingWindowMaximum(vector<int> &nums, int k)
{
    vector<int> ans;

    for (int i = 0; i < nums.size() && nums.size() - i >= k; i++)
    {
        int maxi = INT_MIN;
        for (int j = i; j < k + i; j++)
        {

            maxi = max(maxi, nums[j]);
        }
        ans.push_back(maxi);
    }

    return ans;
}

vector<int> slidingWindowMaximum2(vector<int> &nums, int &k)

{

    deque<int> dq;

    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)

    {

        if (!dq.empty() && dq.front() == i - k)

            dq.pop_front();

        while (!dq.empty() && nums[dq.back()] <= nums[i])

            dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1)

            ans.push_back(nums[dq.front()]);
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

    int num = 3;

    print(v);

    vector<int> ans = slidingWindowMaximum2(v, num);

    cout << "Maximum Sliding Window : " << endl
         << endl;

    print(ans);
}