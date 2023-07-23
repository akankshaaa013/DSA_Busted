#include <bits/stdc++.h>
using namespace std;

// * TIME COMPLEXITY : O(N)
int KadanesAlgo(vector<int> &v, vector<int> &temp)
{
    int sum = 0;
    int maxSum = INT_MIN;
    int start;
    int ansStart = -1;
    int ansEnd = -1;
    for (int i = 0; i < v.size(); i++)
    {

        if (sum == 0)
            start = i;
        sum += v[i];

        if (sum > maxSum)
        {
            maxSum = sum;
            ansStart = start;
            ansEnd = i;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }

    for (int i = ansStart; i <= ansEnd; i++)
    {
        temp.push_back(v[i]);
    }
    return maxSum;
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

    cout << "Subarray with maximum sum is : ";
    vector<int> ans;
    int sum = KadanesAlgo(v, ans);
    for (auto it : ans)
    {
        cout << it << "   ";
    }

    cout << "\nThe sum is : " << sum << endl;
}