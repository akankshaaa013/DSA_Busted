#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Storing pairs in stack.
// T.C -> O(1)
// S.C -> O(2n)
class minStack
{
    stack<pair<int, int>> st;

public:
    // Function to add another element equal to num at the top of stack.
    void push(int num)
    {
        if (st.empty())
        {
            st.push({num, num});
            return;
        }

        int mini = min(st.top().second, num);

        st.push({num, mini});
    }

    // Function to remove the top element of the stack.
    int pop()
    {
        if (st.empty())
            return -1;

        int x = st.top().first;
        st.pop();
        return x;
    }

    // Function to return the top element of stack if it is present. Otherwise return -1.
    int top()
    {
        if (st.empty())
            return -1;

        int x = st.top().first;
        return x;
    }

    // Function to return minimum element of stack if it is present. Otherwise return -1.
    int getMin()
    {
        if (st.empty())
            return -1;

        int x = st.top().second;

        return x;
    }
};



// Approach 2 : Formula based Implementation
// T.C -> O(1)
// S.C -> O(n)
class MinStack
{
public:
    stack<long long> st;
    long long mini;

    MinStack()
    {

        while (!st.empty())
        {
            st.pop();
        }

        mini = INT_MAX;
    }

    void push(int val)
    {

        long long value = val;

        if (st.empty())
        {
            st.push(value);
            mini = value;
        }
        else
        {
            if (value < mini)
            {
                st.push((2 * value * 1LL - mini));
                mini = value;
            }
            else
            {
                st.push(value);
            }
        }
    }

    void pop()
    {

        if (st.empty())
            return;

        if (st.top() < mini)
        {
            mini = 2 * mini - st.top();
        }
        st.pop();
    }

    int top()
    {

        if (st.empty())
            return -1;

        if (st.top() < mini)
            return mini;

        return st.top();
    }

    int getMin()
    {

        return mini;
    }
};

int main()
{
}