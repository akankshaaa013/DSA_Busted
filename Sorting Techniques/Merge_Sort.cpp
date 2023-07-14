#include <bits/stdc++.h>
using namespace std;

void Merge(vector<int>& arr,int low,int mid,int high){
    
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