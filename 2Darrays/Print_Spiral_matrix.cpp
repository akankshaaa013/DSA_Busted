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

vector<int> Print_Spiral_matrix(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    vector<int> ans;

    int top = 0;          // top row.
    int bottom = row - 1; // Bottom Row.

    int left = 0;        // 1st column.
    int right = col - 1; // last column.

    while (top <= bottom && left <= right)
    {

        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;
}

int main()
{

    vector<vector<int>> arr;
    int m, n;
    cout << "Enter the rows and cols : ";
    cin >> m >> n;
    cout << "Enter the matrix elements :\n ";

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
    vector<int> ans = Print_Spiral_matrix(arr);
    cout << endl;
    for (auto it : ans)
    {
        cout << it << "  ";
    }
}