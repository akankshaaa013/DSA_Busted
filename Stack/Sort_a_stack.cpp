#include <bits/stdc++.h>
using namespace std;

void SortMin(stack<int> &st, int x)
{

    if (st.empty() || st.top() < x)
    {
        st.push(x);
        return;
    }

    int num = st.top();
    st.pop();

    SortMin(st, x);

    st.push(num);
}

void sortStack(stack<int> &st)
{

    if (st.empty())
    {
        return;
    }

    int x = st.top();
    st.pop();

    sortStack(st);

    SortMin(st, x);
}

void printStack(stack<int> st)
{

    if (st.empty())
    {
        return;
    }

    int x = st.top();

    st.pop();

    cout << x << endl;

    printStack(st);

    st.push(x);
}

int main()
{
    stack<int> st;

    int size;

    cout << "Enter the stack size : ";
    cin >> size;

    cout << "Enter the Stack Elements : ";

    for (int i = 0; i < size; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }

    printStack(st);

    sortStack(st);

    cout << endl
         << "Sorted stack : " << endl;

    printStack(st);
}