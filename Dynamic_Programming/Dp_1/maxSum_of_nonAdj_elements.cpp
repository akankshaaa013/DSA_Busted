#include <bits/stdc++.h>
using namespace std;

// Memoization
// T.C : O(N)
// S.C : O(N) + O(N)
int solveM(int idx, vector<int> &nums, vector<int> &dp)
{
    if (idx == 0)
        return nums[0];

    if (idx < 0)
        return 0;

    if (dp[idx] != -1)
        return dp[idx];

    int pick = nums[idx] + solveM(idx - 2, nums, dp);

    int notPick = 0 + solveM(idx - 1, nums, dp);

    return dp[idx] = max(pick, notPick);
}

// Tabulation
// T.C : O(N)
// S.C : O(N)
int solveT(int idx, vector<int>& nums, vector<int>& dp)
{
    dp[0] = nums[0];

    int n = nums.size();

    for(int i = 1; i < n; i++)
    {
        int pick = nums[i];

        if(i > 1) pick += dp[i-2]; 

        int notPick = 0 + dp[i-1];

        dp[i] = max(pick, notPick);
    }
    return dp[n-1];
}

// Tabulation
// T.C : O(N)
// S.C : O(1)
int solveSO(int idx, vector<int>& nums)
{
    int prev1 = nums[0];

    int prev2 = 0;

    int n = nums.size();

    for(int i = 1; i < n; i++)
    {
        int pick = nums[i];

        if(i > 1) pick += prev2; 

        int notPick = 0 + prev1;

        int curr = max(pick, notPick);

        prev2 = prev1;
        prev1 = curr;

    }
    return prev1;
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

    vector<int> dp(n, -1);

    cout << "Maximum Sum of Non_Adjacent Elements are  : " << solveM(n - 1, v, dp) << endl;
}
