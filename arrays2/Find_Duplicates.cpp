#include <bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY : O(N).
// SPACE COMPLEXITY : O(1).
//* Using mark visited method finds the 1st repeating number.
int find_first_Duplicate(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]) - 1;

        // mark as visited
        nums[index] *= -1;
        // incase of duplicate, this will become +ve
        if (nums[index] > 0)
            return abs(nums[i]);
    }
    return -1;
}

// TIME COMPLEXITY : O(N).
// SPACE COMPLEXITY : O(N).
// *Using Hashing finds the last repeating number.
int findDuplicate2(vector<int> &nums)
{
    unordered_map<int, int> mpp;

    for (int i = 0; i < nums.size(); i++)
    {
        mpp[nums[i]]++;
        if (mpp[nums[i]] == 2)
        {
            return nums[i];
        }
    }
    return -1;
}

// TIME COMPLEXITY : O(N).
// SPACE COMPLEXITY : O(N).
// *Using sorting method finds the last repeating number.
int findDuplicate3(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            if(nums[i]==nums[i+1]){
                return nums[i];
            }
        }
        return -1;
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

    cout << "Repeating number is : " << find_first_Duplicate(v) << endl;
    cout << "Repeating number is : " << findDuplicate2(v) << endl;
    cout << "Repeating number is : " << findDuplicate3(v) << endl;
}