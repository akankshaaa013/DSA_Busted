#include <bits/stdc++.h>
using namespace std;

/*
COMPLEXITY ANALYSIS : 
Since everytime the array is divided from partiion Index so the time complexity of recursive call is O(log n).

For Partition function all the elements of the array are traversed, so the time complexity of partition() function is O(n).

The total Time complexity is O(n*log n).

Space Complexity : O(1).

Worst Case Complexity : O(n^2) [ If the pivot element chosen is smallest or the largest element of the array. ]
*/

int partition(vector<int> &arr, int low, int high)
{

    int pivot = arr[low];

    int i = low, j = high;

    while (i < j)
    {

        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);

    return j;
}

void Quick_Sort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int partition_Index = partition(arr, low, high);
        Quick_Sort(arr, low, partition_Index - 1);
        Quick_Sort(arr, partition_Index + 1, high);
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

    Quick_Sort(v, 0, n - 1);

    for (auto i : v)
    {
        cout << i << "  ";
    }
}