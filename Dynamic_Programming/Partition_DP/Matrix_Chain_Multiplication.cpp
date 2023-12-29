#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<int>& arr, vector<vector<int>>& dp)
{
    if(i == j)  return 0;

    if(dp[i][j] != -1)  return dp[i][j];

    int mini = 1e9;

    for(int k = i; k < j; k++)
    {
        int steps = arr[i-1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k + 1, j, arr, dp);
        if(steps < mini)    mini = steps;
    }

    return dp[i][j] = mini;
}

int fT(int n, vector<int>& arr, vector<vector<int>>& dp)
{
    for(int i = 0; i < n; i++)      dp[i][i] = 0;

    for(int i = n - 1; i >= 1; i--)
    {
        for(int j = i + 1; j < n; j++)
        {
            int mini = 1e9;

            for(int k = i; k < j; k++)
            {
                int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                if(steps < mini)    mini = steps;
            }

            dp[i][j] = mini;
        }
    }

    return dp[1][n-1];
}

int matrixChainMultiplication(vector<int>& arr, int n) {

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return fT(n, arr, dp);

}

int main()
{
    vector<int> v;
    int n;
    cout << "Enter the size of array : ";
    cin >> n;

    cout << "Enter the array elements : ";
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    cout << "Minimum no. of Operations required are : " << matrixChainMultiplication(v, n) << endl;
}