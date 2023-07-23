#include <bits/stdc++.h>
using namespace std;

/*
*Step 1 : Using morre's voting algorithm find the candidate element.
*Step 2 : Using another for loop check if the candidate element appears for more than n/2 times or not.

*TIME COMPLEXITY : O(n) -> 1st for loop.
                  *O(n) -> 2nd for loop.
                   _______
                  *|O(2n)|
                   *******
*/

int majorityElement(vector<int> &nums)
{
    int count = 0;
    int element;

    for (unsigned int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {
            element = nums[i];
            count++;
        }
        else if (nums[i] == element)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    int count2 = 0;
    for (unsigned int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == element)
            count2++;
    }

    if (count2 > (nums.size() / 2))
        return element;

    return -1;
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

    int ans = majorityElement(v);

    if (ans != -1)
    {
        cout << "Element occuring for more than n/2 times is : " << ans << endl;
    }
    else
    {
        cout << "No element occurs for more than n/2 times :)" << endl;
    }
}