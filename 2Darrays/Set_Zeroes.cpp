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

//* BETTER APPROACH
//* Time Complexity : O(2*(m*n)) Space complexity : O(m+n)
void SetZeroes2(vector<vector<int>> &matrix)
{

    int r = matrix.size();
    int c = matrix[0].size();
    vector<int> row(r, 0);
    vector<int> col(c, 0);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (row[i] || col[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}

//* OPTIMIZED APPROACH
//* Time Complexity : O(2*(m*n)) Space complexity : O(1)
void setZeroes(vector<vector<int>> &matrix)
{
    int r = matrix.size();
    int c = matrix[0].size();

    int col0 = 1;
    //* vector<int> row(r,0); --> matrix[..][0]
    //* vector<int> col(c,0); --> matrix[0][..]

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (matrix[i][j] == 0)
            {
                //* mark the i-th row
                matrix[i][0] = 0;
                //* mark the j-th col

                if (j != 0)
                {
                    matrix[0][j] = 0;
                }
                else
                {
                    // For 0-th location of column mark col0 to 0.
                    col0 = 0;
                }
            }
        }
    }

    // Mark the matrix 0 except for 0-th row and 0-th col which is acting as a hashmap.
    for (int i = 1; i < r; i++)
    {
        for (int j = 1; j < c; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < c; j++)
            matrix[0][j] = 0;
    }

    if (col0 == 0)
    {
        for (int i = 0; i < r; i++)
        {
            matrix[i][0] = 0;
        }
    }
}

int main()
{

    vector<vector<int>> arr;
    int m, n;
    cout << "Enter the rows and cols : ";
    cin >> m >> n;

    cout << "Enter the matrix elements : \n";
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
    setZeroes(arr);
    cout << endl;
    print2dVector(arr);
}