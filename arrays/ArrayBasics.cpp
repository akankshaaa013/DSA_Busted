#include <bits/stdc++.h>
using namespace std;

// T.C : O(n)
// Returns the largest element of the array.
int largestElement(vector<int> arr)
{
    int max = INT_MIN;

    for (auto i : arr)
    {
        if (i > max)
        {
            max = i;
        }
    }
    return max;
}

// T.C : O(n)
// Returns the smallest element of the array.
int smallestElement(vector<int> arr)
{
    int min = INT_MAX;

    for (auto i : arr)
    {
        if (i < min)
        {
            min = i;
        }
    }
    return min;
}

// T.C : O(n)
// Returns the second largest element of the array.
int secondLargest(vector<int> arr)
{
    int maxElement = arr[0];
    int sec_largest = INT_MIN;

    for (unsigned int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > maxElement)
        {
            sec_largest = maxElement;
            maxElement = arr[i];
        }
        else if (arr[i] < maxElement && arr[i] > sec_largest)
        {
            sec_largest = arr[i];
        }
    }
    return sec_largest;
}

// T.C : O(n)
// Returns the second smallest element of the array.
int secondSmallest(vector<int> arr)
{
    int minElement = arr[0];
    int sec_mini = INT_MAX;

    for (unsigned int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < minElement)
        {
            sec_mini = minElement;
            minElement = arr[i];
        }
        else if (arr[i] > minElement && arr[i] < sec_mini)
        {
            sec_mini = arr[i];
        }
    }
    return sec_mini;
}

// T.C : O(n)
// Check if the array is sorted & rotated.
bool Check(vector<int> arr, int n)
{
    int count = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            count++;
        }
    }

    if (arr[n - 1] > arr[0])
    {
        count++;
    }
    return count <= 1;
}

// T.C : O(n)
// Remove duplicates (in-place) from the array.
void RemoveDuplicates(vector<int> arr, int n)
{
    int i = 0;
    int j = 1;
    while (j < n)
    {
        if (arr[i] != arr[j])
        {
            arr[i + 1] = arr[j];
            i++;
        }
        j++;
    }

    for (int it = 0; it <= i; it++)
    {
        cout << arr[it] << "  ";
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

    cout << "Second largest element is : " << secondLargest(arr) << endl;

    cout << "Second smallest element is : " << secondSmallest(arr) << endl;

    if (Check(arr, n))
    {
        cout << "Array is Sorted & Rotated :)" << endl;
    }
    else
    {
        cout << "Array is NOT Sorted & Rotated :(" << endl;
    }

    RemoveDuplicates(arr, n);
}