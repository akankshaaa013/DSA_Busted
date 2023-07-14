#include <bits/stdc++.h>
using namespace std;

/*
Best Case complexity : O(n) [If the array is already sorted.]
Average Case complexity : O(n^2)
Worst Case complexity : O(n^2)
*/

void Insertion_Sort(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j], arr[j - 1]);
            j--;
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

    Insertion_Sort(v, n);

    for (auto i : v)
    {
        cout << i << "  ";
    }
}