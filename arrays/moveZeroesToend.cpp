#include <bits/stdc++.h>
using namespace std;

void moveZeroesToEnd(vector<int> &arr, int n)
{

    int i;
    int j = 0;
    while (arr[j] != 0)
    {
        j++;
    }

    i = j + 1;

    for (; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main()
{

    int n;
    vector<int> arr;
    cout << "Enter the size of the array : ";
    cin >> n;
    cout << "Enter the vector elements : ";
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    moveZeroesToEnd(arr, n);

    for (auto it : arr)
    {
        cout << it << "   ";
    }
}