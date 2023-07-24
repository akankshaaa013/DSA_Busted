#include <bits/stdc++.h>
using namespace std;

void print2dVector(vector<vector<int>> arr)
{
    for (auto i : arr)
    {
        for (auto j : i)
        {
            cout << j << "   ";
        }
        cout << endl;
    }
}

void Print_Spiral_matrix(vector<vector<int>> &matrix)
{
    
}

int main()
{

    vector<vector<int>> arr;
    int m, n;
    cout << "Enter the rows and cols : ";
    cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            temp.push_back(a);
        }
        arr.push_back(temp);
    }

    print2dVector(arr);
    Print_Spiral_matrix(arr);
    cout << endl;
    print2dVector(arr);
}