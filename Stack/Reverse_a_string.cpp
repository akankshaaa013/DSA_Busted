#include<bits/stdc++.h>
using namespace std;

void ReverseStringUsingStack(string& s){

    stack<char> st;

    while(!s.empty()){
        st.push(s[0]);
        s.erase(s.begin());
    }

    while(!st.empty()){
        s += st.top();
        st.pop();
    }

}

int main(){

    string s;
    cout<<"Enter the string : ";
    getline(cin,s);

    cout<<"Orignal String is : "<<s<<endl<<endl;

    ReverseStringUsingStack(s);

    cout<<"Reversed String is : "<<s<<endl;

}