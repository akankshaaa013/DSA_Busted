#include <bits/stdc++.h>
using namespace std;

//* TIME COMPLEXITY : O(n)
//* SPACE COMPLEXITY : 0(n).
int Subarray_with_XOR_k(vector<int> nums, int k)
{
    int cnt = 0;
    int preXOR = 0;

    unordered_map<int, int> mpp;

    for (unsigned int i = 0; i < nums.size(); i++)
    {
        preXOR = preXOR ^ nums[i];

        if (preXOR == k)
        {
            cnt += 1;
        }

        int x = preXOR ^ k;

        cnt += mpp[x];

        mpp[preXOR]++;
    }
    return cnt;
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

    int k;
    cout << "Enter the target xor value : ";
    cin >> k;

    int cnt = Subarray_with_XOR_k(v, k);

    cout << "\nNo. of subarrays with xor k is : " << cnt << endl;
}
