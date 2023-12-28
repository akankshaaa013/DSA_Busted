#include <bits/stdc++.h>
using namespace std;

// A list of string is said to be a longest string chain if and only if the 2 adjacent strings differ by one character.
bool isChain(string &s1, string &s2)
{
    int s1Len = s1.size();

    if (s1Len != s2.size() + 1)
        return false;

    int i = 0, j = 0;

    while (i < s1Len)
    {
        if (s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
            i++;
    }

    return i == s1Len && j == s2.size();
}

static bool comp(string &s1, string &s2)
{
    return s1.size() < s2.size();
}

int longestStringChain(vector<string> &words, int n)
{
    sort(words.begin(), words.end(), comp);

    vector<int> dp(n, 1), hash(n);
    for (int i = 0; i < n; i++)
        hash[i] = i;

    int maxi = 1, idx = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (isChain(words[i], words[j]) && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                hash[i] = j;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            idx = i;
        }
    }

    vector<string> ans;

    while (hash[idx] != idx)
    {
        ans.push_back(words[idx]);
        idx = hash[idx];
    }

    ans.push_back(words[idx]);

    reverse(ans.begin(), ans.end());

    for (auto it : ans)
    {
        cout << it << "  ";
    }

    cout << endl;

    return maxi;
}

int main()
{
    vector<string> v;
    int n;
    cout << "Enter the size of array : ";
    cin >> n;

    cout << "Enter the array elements : ";
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        v.push_back(a);
    }

    cout << "Length of the longest string chain is : " << longestStringChain(v, n) << endl;
}