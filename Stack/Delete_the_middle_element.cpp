#include<bits/stdc++.h>
using namespace std;

void printStack(stack<int> st){

    if(st.empty()){
        return;
    }

    int x = st.top();

    st.pop();

    cout<<x<<"  ";
    printStack(st);

    st.push(x);
}


// T.C -> O(n)
// S.C -> O(n)
// Iterative Approach
void deleteMiddle(stack<int>&inputStack, int N){
	
   int midIndex = N/2;

   stack<int> st;

   while(midIndex != 0){
      st.push(inputStack.top());
      inputStack.pop();
      midIndex--;
   }

   inputStack.pop();

   while(!st.empty()){
      inputStack.push(st.top());
      st.pop();
   } 
}

// Recursive Approach
void deleteMiddle(stack<int>&inputStack, int size,int count){

    if(count == (size/2)){
        inputStack.pop();
        return;
    }

    int x = inputStack.top();
    inputStack.pop();

    deleteMiddle(inputStack, size, count+1);

    inputStack.push(x);

}

int main(){

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

    cout<<endl<<"Stack Before deleting the middle element : "<<endl;
    printStack(st);

    deleteMiddle(st,size,0);

    cout<<endl<<endl<<"Stack after deleting the middle element : "<<endl;

    printStack(st);

    

}