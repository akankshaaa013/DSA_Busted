#include <bits/stdc++.h>
using namespace std;

int lcs(string &str1, string &str2){
    
    int n = str1.length();
    int m = str2.length();

    int ans = -1;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(str1[i-1] == str2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }
            else dp[i][j] = 0;
        }
    }
    return ans;
}
int lcsSO(string &str1, string &str2){
    
    int n = str1.length();
    int m = str2.length();

    int ans = -1;

    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(str1[i-1] == str2[j-1])
            {
                curr[j] = 1 + prev[j-1];
                ans = max(ans, curr[j]);
            }
            else curr[j] = 0;
        }
        prev = curr;
    }
    return ans;
}

int main()
{
    string s1, s2;

    cout << "Enter the string s1 & s2 : ";
    cin >> s1 >> s2;

    cout << endl
         << "The Longest Common Substring is : " << lcsSO(s1, s2) << endl;
}