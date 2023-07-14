#include <bits/stdc++.h>
using namespace std;

/*
Best / Average / Worst Case complexity : O(n^2)
*/

void Selection_Sort(vector<int> &v, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[minIndex] > v[j])
            {
                minIndex = j;
            }
        }
        swap(v[minIndex], v[i]);
    }
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

    Selection_Sort(v, n);

    for (auto i : v)
    {
        cout << i << "  ";
    }
}