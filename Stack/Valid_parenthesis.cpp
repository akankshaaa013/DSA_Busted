#include <bits/stdc++.h>
using namespace std;

// The below problem can also be solved without using hashmap.
// Approach : T.C -> O(n).

bool isValidParenthesis(string s)
{
    map<char, int> mpp = {{'(', -1}, {')', 1}, {'[', -2}, {']', 2}, {'{', -3}, {'}', 3}};

    stack<char> st;

    for (unsigned int i = 0; i < s.length(); i++)
    {

        char c = s[i];

        if (mpp[c] < 0)
        {
            st.push(c);
        }
        else
        {
            if (!st.empty())
            {
                if (mpp[st.top()] + mpp[c] == 0)
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    return st.empty() ? true : false;
}

int main()
{

    string s;
    cout << "Enter the Parenthesis Expression : ";
    getline(cin, s);

    if (isValidParenthesis(s))
    {
        cout << "B A L A N C E D" << endl;
    }
    else
    {
        cout << "N O T   B A L A N C E D" << endl;
    }
}