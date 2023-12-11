#include<bits/stdc++.h>
using namespace std;

// Using Memoization (Top - Down Approach)
// T.C -> O(n)
// S.C -> O(n) + O(n)
int fibo(int n, vector<int>& dp)
{
    if(n <= 1) return n;

    if(dp[n] != -1) return dp[n];

    return dp[n] = fibo(n-1, dp) + fibo(n-2, dp);
}

// Using Tabulation (Bottom - Up Approach)
// T.C -> O(n)
// S.C -> O(n)
int fibo2(int n, vector<int>& dp)
{
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// Optimized Approach
// T.C -> O(n)
// S.C -> O(1)
int fibo3(int n)
{
    int prev1 = 1;
    int prev2 = 0;

    for(int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
int main()
{
    int n;
    
    cout<<"Enter the value of n : ";
    cin>>n;

    vector<int> dp(n + 1, -1);
    
    cout<<"N-th Fibonacci number is : "<< fibo(n, dp) << endl;
    cout<<"N-th Fibonacci number is : "<< fibo2(n, dp) << endl;
    cout<<"N-th Fibonacci number is : "<< fibo3(n) << endl;
}
