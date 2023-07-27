#include <bits/stdc++.h>
using namespace std;

//* TIME COMPLEXITY : O(n)

int Subarray_with_sum_k(vector<int> nums, int k)
{
    int cnt = 0;
    int preSum = 0;

    unordered_map<int, int> mpp;

    for (int i = 0; i < nums.size(); i++)
    {

        preSum += nums[i];

        if (preSum == k)
        {
            cnt++;
        }

        //if (presum-k) exists in map then it's value will be added else 0 will be added.
        cnt += mpp[preSum - k];

        mpp[preSum]++;
    }

    return cnt;
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
    cout << "Enter the target sum : ";
    cin >> k;

    int cnt = Subarray_with_sum_k(v, k);

    cout << "\nNo. of subarrays with sum k is : " << cnt << endl;
}
