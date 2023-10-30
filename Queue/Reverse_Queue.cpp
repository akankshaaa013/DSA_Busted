#include <bits/stdc++.h>
using namespace std;

void print(queue<int> q, int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << q.front() << "   ";
        q.pop();
    }

    cout << endl;
}

// Approach 2 : using stack

void reverse2(queue < int > & q) {
    
    stack<int> st;

    int n = q.size();

    for(int i = 0 ; i < n ; i++){
        st.push(q.front());
        q.pop();
    }

    for(int i = 0 ; i < n ; i++){
        q.push(st.top());
        st.pop();
    }

}

// Approach 1 : Using recursion
void reverse(queue < int > & q,int n) {
    if(q.empty() || n <= 0){
        return;
    }

    int num = q.front();

    q.pop();

    reverse(q,n-1);

    q.push(num);
}

// Reverse 1st k elements

queue<int> reverseElements(queue<int> q, int k)
{
    reverse(q,k);

    int n = q.size();
    
    for(int i = 0 ; i < n - k ; i++){
        q.push(q.front());
        q.pop();
    }
    
    return q;
}

int main()
{
    queue<int> q;
    int n;
    cout << "Enter the size of the queue : ";
    cin >> n;
    cout << "Enter the queue elements : ";

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    print(q,n);

    queue<int> ans = reverseElements(q,4);

    print(ans,n);
}