#include <bits/stdc++.h>
using namespace std;

/*
Best Case complexity : O(n) [If the array is already sorted.]
Average Case complexity : O(n^2)
Worst Case complexity : O(n^2)
*/

void Bubble_Sort(vector<int> &arr, int n)
{

    for (int i = n - 1; i > 0; i--)
    {
        bool swapped = false;
        for (int j = 0; j < i; j++)
        {

            if (arr[j + 1] < arr[j])
            {
                swap(arr[j + 1], arr[j]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            return;
        }
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

    Bubble_Sort(v, n);

    for (auto i : v)
    {
        cout << i << "  ";
    }
}