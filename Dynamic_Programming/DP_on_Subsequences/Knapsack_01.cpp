#include<bits/stdc++.h>
using namespace std;

int solve(int idx, int maxWeight, vector<int>& weight, vector<int>& value, vector<vector<int>>& dp)
{
	if(idx == 0)
	{
		if(weight[0] <= maxWeight)	return value[0];

		return 0;
	}

	if(dp[idx][maxWeight] != -1)	return dp[idx][maxWeight];

	int pick = 0 + solve(idx - 1, maxWeight, weight, value, dp);

	int notPick = INT_MIN;

	if(weight[idx] <= maxWeight)	notPick = value[idx] + solve(idx - 1, maxWeight - weight[idx], weight, value, dp);

	return dp[idx][maxWeight] = max(pick, notPick);
}

int solveT(int n, int maxWeight, vector<int>& weight, vector<int>& value, vector<vector<int>>& dp)
{
	for(int i = weight[0]; i <= maxWeight; i++)		dp[0][i] = value[0];

	for(int idx = 1; idx < n; idx++)
	{
		for(int wt = 0; wt <= maxWeight; wt++)
		{
			int notPick = 0 + dp[idx - 1][wt];

			int pick = INT_MIN;

			if(weight[idx] <= wt)
			{
				pick = value[idx] + dp[idx - 1][wt - weight[idx]];
			}

			dp[idx][wt] = max(pick, notPick);
		}
	}
	return dp[n-1][maxWeight];
}

int solveSO(int n, int maxWeight, vector<int>& weight, vector<int>& value)
{
	vector<int> prev(maxWeight + 1, 0), curr(maxWeight + 1, 0);

	for(int i = weight[0]; i <= maxWeight; i++)		prev[i] = value[0];

	for(int idx = 1; idx < n; idx++)
	{
		for(int wt = 0; wt <= maxWeight; wt++)
		{
			int notPick = 0 + prev[wt];

			int pick = INT_MIN;

			if(weight[idx] <= wt)
			{
				pick = value[idx] + prev[wt - weight[idx]];
			}

			curr[wt] = max(pick, notPick);
		}
		prev = curr;
	}
	return prev[maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

	return solveSO(n, maxWeight, weight, value);
}

int main(){  

    int n, wt;

    cout<<"Enter the value of n & maxWeight : ";
    cin >> n >> wt;

    vector<int> weight(n), value(n);

    cout<<"Enter the weight value pair : ";
    for(int i = 0; i < n; i++)
    {
        int x,y;
        cin >> x >> y;
        weight[i] = x;
        value[i] = y;
    }
    cout<<endl<<"Max value is : " << knapsack(weight, value, n, wt);
}