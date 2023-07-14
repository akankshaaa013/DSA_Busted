#include <bits/stdc++.h>
using namespace std;

/*
TIME COMPLEXITY ANALYSIS :
Everytime the function is called recursiely of halfs of the array. So the time complexity of recursive call is O(log n).

After the function returns the merge operation is performed and since in wrst case n comparisons are performed for n-sized array
so the time complexity of merge() function is O(n).

The total time complexity is O(n*log n).
*/

void Merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int i = low;
    int j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }

    while (j <= high)
    {
        temp.push_back(arr[j++]);
    }

    for (int index = low; index <= high; index++)
    {
        // Starting index of temp is 0.
        arr[index] = temp[index - low];
    }
}

void Merge_Sort(vector<int> &arr, int low, int high)
{
    if (low == high)
    {
        return;
    }

    int mid = low + (high - low) / 2;
    Merge_Sort(arr, low, mid);
    Merge_Sort(arr, mid + 1, high);

    Merge(arr, low, mid, high);
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

    Merge_Sort(v, 0, n - 1);

    for (auto i : v)
    {
        cout << i << "  ";
    }
}