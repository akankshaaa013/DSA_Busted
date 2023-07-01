#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s,int st){
    //Base Case.
    if(s[st]!=s[s.length()-st-1]) return false;

    if(st>(s.length()-st-1)) return true;
    st++;
    
    //Recursive Call
    return isPalindrome(s,st);
}

void reverseString(string &s,int st,int e){

    //Base Case.
    if(st>e) return;
    
    swap(s[st],s[e]);
    st++;
    e--;
    //Recursive Call
    reverseString(s,st,e);
}

int main(){
    string s;
    cout<<"Enter the String : ";
    cin>>s;
    int st=0;
    int e=s.length()-1;
    reverseString(s,st,e);
    cout<<"Reversed String is : "<<s<<endl;
    

    if(isPalindrome(s,0)) cout<<"String is Palindrome :)"<<endl;
    else cout<<"String is Not Palindrome :)"<<endl;

}