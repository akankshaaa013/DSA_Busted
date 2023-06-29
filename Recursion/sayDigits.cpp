#include<bits/stdc++.h>
using namespace std;

void printNum(int n){
    switch(n){
        case 0: cout<<"Zero ";
        break;
        case 1 : cout<<"One ";
        break;
        case 2 : cout<<"Two ";
        break;
        case 3 : cout<<"Three ";
        break;
        case 4 : cout<<"Four ";
        break;
        case 5 : cout<<"Five ";
        break;
        case 6 : cout<<"Six ";
        break;
        case 7 : cout<<"Seven ";
        break;
        case 8 : cout<<"Eight ";
        break;
        case 9 : cout<<"Nine ";
        break;
    }
    return;
}

void sayDigits(int n){
    if(n==0) return;

    sayDigits(n/10);
    printNum(n%10);
}

int sum_of_Digits(int n){
    if(n==0) return 0;

    return (n%10)+sum_of_Digits(n/10);
}

int main(){

    int x;
    cin>>x;
    cout<<"Sum of Digits is : "<<sum_of_Digits(x)<<endl;
    sayDigits(sum_of_Digits(x));
}