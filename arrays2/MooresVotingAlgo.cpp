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


/*
*Step 1 : Using moore's voting algorithm select 2 candidate elements.
*Step 2 : Using another for loop check if both the candidate element appears for more than n/3 times or not.

*TIME COMPLEXITY : O(n) -> 1st for loop.
                  *O(n) -> 2nd for loop.
                   _______
                  *|O(2n)|
                   *******
*/
pair<int,int> majorityElement2(vector<int> &nums)
{

    pair<int,int> ans;

    ans.first=-1;
    ans.second=-1;

    int cnt1 = 0, cnt2 = 0;
    int el1, el2;

    for (int i = 0; i < nums.size(); i++)
    {
        if (cnt1 == 0 && nums[i] != el2)
        {
            cnt1 = 1;
            el1 = nums[i];
        }
        else if (cnt2 == 0 && nums[i] != el1)
        {
            cnt2 = 1;
            el2 = nums[i];
        }
        else if (el1 == nums[i])
            cnt1++;
        else if (el2 == nums[i])
            cnt2++;
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0;
    cnt2 = 0;

    int mini = ((int)nums.size() / 3) + 1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == el1)
            cnt1++;
        else if (nums[i] == el2)
            cnt2++;
    }

    if (cnt1 >= mini)
        ans.first=(el1);
    if (cnt2 >= mini)
        ans.second=(el2);

    return ans;
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

    /*
    int ans = majorityElement(v);

    if (ans != -1)
    {
        cout << "Element occuring for more than n/2 times is : " << ans << endl;
    }
    else
    {
        cout << "No element occurs for more than n/2 times :)" << endl;
    }
    */

    pair<int,int> ans = majorityElement2(v);

    if (ans.first !=-1 && ans.second !=-1 )
    {
        cout << "Element occuring for more than n/3 times is : " << ans.first<<"  "<<ans.second << endl;
    }
    else if (ans.first !=-1 )
    {
        cout << "Element occuring for more than n/3 times is : " << ans.first<< endl;
    }
    else if (ans.second !=-1 )
    {
        cout << "Element occuring for more than n/3 times is : " << ans.second<<endl;
    }
    else
    {
        cout << "No element occurs for more than n/3 times :)" << endl;
    }


}