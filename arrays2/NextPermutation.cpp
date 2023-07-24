#include <bits/stdc++.h>
using namespace std;

/*
*The next permutation of an array of integers is the next lexicographically greater permutation of its integer.
More formally, if all the permutations of the array are sorted in one container according to their lexicographical order,
then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement
is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
*/

//* STEP 1 : Find the peak element/break-point from the last.
//* STEP 2 : Find the smallest element greater than peak element and swap it with the peak element.
//* STEP 3 : Reverse the array from last till index+1. 
void nextPermutation(vector<int> &nums)
{

    int index = -1;
    int n = nums.size();
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    for (int i = n - 1; i >= index; i--)
    {
        if (nums[i] > nums[index])
        {
            swap(nums[i], nums[index]);
            break;
        }
    }

    reverse(nums.begin() + index + 1, nums.end());
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

    nextPermutation(v);

    cout << "Next Permutation of the array is : ";

    for (auto it : v)
    {
        cout << it << " ";
    }
}
