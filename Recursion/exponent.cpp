#include<bits/stdc++.h>
using namespace std;

//Optimized Code for Calculating Exponent of a Number .
long long int calculate_Exponent(int a,int b){
    if(b==0) return 1;

    if(b==1) return a;

    int ans = calculate_Exponent(a,b/2);

    if(b&1) return ans*ans*a;
    else return ans*ans;
}


int main(){
    cout<<"Enter the Value of a & b : ";
    int a,b;
    cin>>a>>b;
    cout<<"a^b = "<<calculate_Exponent(a,b)<<endl;
}