#include <bits/stdc++.h>
using namespace std;

vector<int> union1(vector<int> arr1, vector<int> arr2)
{
    vector<int> ans;

    unsigned n1 = arr1.size();
    unsigned n2 = arr2.size();

    unsigned int i = 0;
    unsigned int j = 0;

    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            if (ans.size() == 0 || ans.back() != arr1[i])
            {
                ans.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (ans.size() == 0 || ans.back() != arr2[j])
            {
                ans.push_back(arr2[j]);
            }
            j++;
        }
    }

    while (i < n1)
    {
        if (ans.size() == 0 || ans.back() != arr1[i])
        {
            ans.push_back(arr1[i]);
        }
        i++;
    }

    while (j < n2)
    {
        if (ans.size() == 0 || ans.back() != arr2[j])
        {
            ans.push_back(arr2[j]);
        }
        j++;
    }
    return ans;
}

vector<int> intersection(vector<int> arr1, vector<int> arr2)
{
    unsigned int n1 = arr1.size();
    unsigned int n2 = arr2.size();

    unsigned int i = 0;
    unsigned int j = 0;
    vector<int> ans;

    while (i < n1 && j < n2)
    {
        if (arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums1;
    vector<int> nums2;
    int m, n;

    cout << "Enter the size of vector 1 : ";
    cin >> m;
    cout << "Enter the vector elements(in lexicographically increasing order) : ";
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        nums1.push_back(a);
    }

    cout << "Enter the size of vector 2 : ";
    cin >> n;
    cout << "Enter the vector elements(in lexicographically increasing order) : ";

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        nums2.push_back(a);
    }

    cout << "\nVector Union is : ";
    vector<int> v = union1(nums1, nums2);
    for (auto i : v)
    {
        cout << i << "  ";
    }

    cout << "\n\nVector Intersection is : ";
    vector<int> v1 = intersection(nums1, nums2);
    for (auto i : v1)
    {
        cout << i << "  ";
    }
}