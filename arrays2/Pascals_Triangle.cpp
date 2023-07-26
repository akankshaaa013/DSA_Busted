#include <bits/stdc++.h>
using namespace std;

//* TYPE : 1
//* Given row and col. Returns the element at that position in the pascal's triangle.
void nCr()
{
    int n, r;
    cout << "Enter the row-th and col : ";
    cin >> n >> r;
    n -= 1;
    r -= 1;

    int ans = 1;

    for (int i = 1; i <= r; i++)
    {
        ans = ans * (n - i + 1);
        ans /= i;
    }

    cout << "Element at nth row and r-th column is : " << ans << endl;
}

//* TYPE 2 :
//* Given row-th no. of pascal triangle. The Function Prints the entire row of the pascal triangle.
// Time Complexity : O(n)
vector<int> print_nth_row(int n)
{
    int ans = 1;
    vector<int> temp;
    temp.push_back(ans);

    for (int i = 1; i < n; i++)
    {
        ans *= (n - i);
        ans /= i;
        temp.push_back(ans);
    }

    return temp;
}

// TYPE-3
//* Given an integer n. Print the Pascal Triangle of size n.
vector<vector<int>> generate(int n)
{
    vector<vector<int>> ans1;
    vector<int> temp;

    for (int i = 1; i <= n; i++)
    {
        ans1.push_back(print_nth_row(i));
    }

    return ans1;
}

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;

    vector<vector<int>> ans = generate(n);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << "    ";
        }
        cout << endl << endl;
    }
}