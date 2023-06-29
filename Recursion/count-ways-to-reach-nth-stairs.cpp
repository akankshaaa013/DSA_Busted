#include<bits/stdc++.h>
using namespace std;

int countDistinctWays(int nStairs) {
    if(nStairs < 0) return 0;
    if(nStairs == 0) return 1;

    return countDistinctWays(nStairs-1)+countDistinctWays(nStairs-2);
}

int main(){

    int n;
    cout<<"Enter the nth stairs : ";
    cin>>n;
    int ans = countDistinctWays(n);
    cout<<ans<<endl;
}