#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int l = 0;
    int r = 0;

    int maxLength = 0;

    int n = s.length();

    map<char, int> mpp;

    while (r < n)
    {
        if (mpp.find(s[r]) != mpp.end())
            l = max(l, mpp[s[r]] + 1);

        mpp[s[r]] = r;
        maxLength = max(maxLength, (r - l + 1));
        r++;
    }
    return maxLength;
}

int main()
{
    string s;
    cout << "Enter the String : ";
    cin >> s;

    cout<<"Length of longest substring without repeating chars : "<<lengthOfLongestSubstring(s)<<endl;
}