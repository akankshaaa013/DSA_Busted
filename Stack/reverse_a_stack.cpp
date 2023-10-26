#include <bits/stdc++.h>
using namespace std;

void pushAtBottom(stack<int> &myStack, int x)
{

    // Base condition
    if (myStack.empty())
    {
        myStack.push(x);
        return;
    }

    int num = myStack.top();
    myStack.pop();
    pushAtBottom(myStack, x);
    myStack.push(num);
}

void reverseStack(stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }

    int num = stack.top();
    stack.pop();
    reverseStack(stack);
    pushAtBottom(stack, num);
}


void printStack(stack<int> st){

    if(st.empty()){
        return;
    }

    int x = st.top();

    st.pop();

    cout<<x<<endl;

    printStack(st);

    st.push(x);
}

int main()
{
    stack<int> st;

    int size;

    cout<<"Enter the stack size : ";
    cin>>size;

    cout<<"Enter the Stack Elements : ";

    for(int i = 0 ; i < size ; i++){
        int x;
        cin>>x;
        st.push(x);
    }

    printStack(st);

    reverseStack(st);

    cout<<endl<<"Reversed stack : "<<endl;

    printStack(st);


}