#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(n + n)
// Space Complexity : O(n)

// Returns Next Greater Element(NGE) for each element. If NGE doesn't exists then prints -1.
vector<int> NextGreaterElements(vector<int> &arr, int n)
{

    stack<int> st;
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {

        int currElement = arr[i];

        while (!st.empty() && currElement >= st.top())
        {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(currElement);
    }
    return ans;
}

// Returns Next Smaller Element(NSE) for each element. If NSE doesn't exists then prints -1.
vector<int> NextSmallerElements(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {

        int currElement = arr[i];

        while (!st.empty() && currElement <= st.top())
        {
            st.pop();
        }

        ans[i] = st.empty() ? -1 : st.top();

        st.push(currElement);
    }
    return ans;
}

// Returns Previous Greater Element(PGE) for each element. If PGE doesn't exists then prints -1.
vector<int> PreviousGreaterElements(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {

        int currElement = arr[i];

        while (!st.empty() && currElement >= st.top())
        {
            st.pop();
        }

        ans[i] = st.empty() ? -1 : st.top();

        st.push(currElement);
    }
    return ans;
}

// Returns Previous Smaller Element(PSE) for each element. If PSE doesn't exists then prints -1.
vector<int> PreviousSmallerElements(vector<int> &arr, int n)
{
    vector<int> ans(n);

    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        int currElement = arr[i];

        while (!st.empty() && currElement <= st.top())
        {
            st.pop();
        }

        ans[i] = st.empty() ? -1 : st.top();

        st.push(currElement);
    }

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

    vector<int> ans = PreviousSmallerElements(v, n);

    for (auto i : ans)
    {
        cout << i << "   ";
    }
}