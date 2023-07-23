#include <bits/stdc++.h>
using namespace std;

//* TIME COMPLEXITY : O(n*log n)
//* SPACE COMPLEXITY : O(n)
pair<int,int> twoSum(vector<int> &nums, int target)
{

    map<int, int> mpp;

    for (unsigned int i = 0; i < nums.size(); i++)
    {

        int num = nums[i];
        int remaining = target - num;

        if (mpp.find(remaining) != mpp.end())
        {
            return {mpp[remaining], i};
        }

        mpp[num] = i;
    }
    return {-1, -1};
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

    int target;
    cout << "Enter the target sum : ";
    cin >> target;

    pair<int,int> p = twoSum(v,target);

    cout<<p.first<<"   "<<p.second<<endl;
}