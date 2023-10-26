#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(string str)
{

    stack<char> st;
    string invalid = "";

    if (str.length() & 1)
        return -1;

    for (int i = 0; i < str.length(); i++)
    {

        char ch = str[i];

        if (ch == '{')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty())
            {
                st.pop();
            }
            else
            {
                invalid += ch;
            }
        }
    }

    while (!st.empty())
    {
        invalid += st.top();
        st.pop();
    }

    int a = 0, b = 0;

    for (auto i : invalid)
    {
        if (i == '{')
            a++;
        else
            b++;
    }

    return (a + 1) / 2 + (b + 1) / 2;
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
    string s;
    cout<<"Enter the string expression : ";
    getline(cin,s);

    int ans = findMinimumCost(s);

    ans != -1? cout<<"Minimum operations to make string valid is "<<ans<<endl : cout<<"String cannot be made valid";

}