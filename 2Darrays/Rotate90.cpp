#include <bits/stdc++.h>
using namespace std;

//* printing the Matrix.
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

void rotate90(vector<vector<int>> &matrix)
{
    int row = matrix.size();

    int col = matrix[0].size();

    //* Transpose The Matrix.

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    //* Reverse Each Row.
    for (int i = 0; i < row; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
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

    rotate90(arr);

    cout << endl;

    print2dVector(arr);
}