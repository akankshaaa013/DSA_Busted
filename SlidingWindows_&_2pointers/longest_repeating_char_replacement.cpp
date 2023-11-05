#include<bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {

        unordered_map<char,int> mpp;

        int ans = 0,left = 0, right = 0;
        int maxF = 0;

        int n = s.length();

        while(right < n)
        {
            mpp[s[right]]++;
            maxF = max(maxF,mpp[s[right]]);

            if((right - left + 1) - maxF > k)
            {
                mpp[s[left]]--;
                left++;
            }

            ans = max(ans,(right - left + 1));
            right++;
        }
        return ans;
    }

int main()
{
    string s;
    cout << "Enter the String : ";
    cin >> s;

    int k;
    cout<<"Enter the value k : ";
    cin>>k;

    cout<<"Length of longest substring with repeating characters after performing k operations  : "<<characterReplacement(s,k)<<endl;
}