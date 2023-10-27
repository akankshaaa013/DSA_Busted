#include <bits/stdc++.h>
using namespace std;

int priority(char c)
{
    if (c == '(' || c == ')')
        return 0;

    if (c == '+' || c == '-')
        return 1;

    if (c == '/' || c == '*')
        return 2;

    if (c == '^')
        return 3;

    return -1;
}

string infixToPostfix(string exp)
{

    stack<char> st;

    string res = "";

    for (unsigned int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        if (isalnum(ch))
        {
            res.push_back(ch);
        }
        else if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && (priority(st.top()) >= priority(ch)))
            {
                res += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    return res;
}

string prefixToPostfix(string s)
{

    stack<string> st;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (isalnum(s[i]))
        {
            string op(1, s[i]);
            st.push(op);
        }
        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            string op(1, s[i]);
            string subExp = op1 + op2 + op;

            st.push(subExp);
        }
    }

    return st.top();
}

string prefixToInfixConversion(string &s)
{

    stack<string> st;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        char ch = s[i];

        if (isalnum(ch))
        {
            string op(1, s[i]);
            st.push(op);
        }
        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            string op3 = "(" + op1 + ch + op2 + ")";
            st.push(op3);
        }
    }

    return st.top();
}

string postfixToPrefix(string &s)
{

    stack<string> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (isalnum(s[i]))
        {
            string op(1, s[i]);
            st.push(op);
        }
        else
        {
            string op2 = st.top();
            st.pop();

            string op1 = st.top();
            st.pop();

            string exp = s[i] + op1 + op2;
            st.push(exp);
        }
    }
    return st.top();
}


string postToInfix(string s) {

    stack<string> st;

    for(int i = 0 ; i < s.length() ; i++)
    {
        if(isalnum(s[i]))
        {
            string op(1,s[i]);
            st.push(op);
        }
        else
        {
            string op2 = st.top();
            st.pop();

            string op1 = st.top();
            st.pop();

            string exp = "(" + op1 + s[i] + op2 + ")";
            st.push(exp);
        }
    }
    return st.top();
    
}



int main()
{
    string s;
    cout << "Enter the expression : ";
    cin >> s;

    string ans = infixToPostfix(s);
    cout << endl
         << ans << endl;
}