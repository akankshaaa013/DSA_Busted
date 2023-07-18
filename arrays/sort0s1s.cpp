#include <bits/stdc++.h>
using namespace std;

void sortZeroesAndOne(vector<int> &arr, int size)
{
    int i = 0;
    int j = size - 1;

    while (i < j)
    {
        if (arr[i] > arr[j])
        {
            swap(arr[i++], arr[j--]);
        }
        else if (arr[i] == 0)
        {
            i++;
        }
        else
        {
            j--;
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

    sortZeroesAndOne(arr, n);

    for (auto it : arr)
    {
        cout << it << "   ";
    }
}