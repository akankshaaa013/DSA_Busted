#include<bits/stdc++.h>
using namespace std;

//Program to check if it is possible to make an vector a non-decreasing vector by modifying atmost one element.
bool isPossible(vector<int> &arr,int n){

    bool changed = false;

    for(int i=0;i<n;i++){
        if(arr[i]<=arr[i+1]) continue;
        else{
            if(changed) return false;
            else{
                if(i==0||arr[i-1]<=arr[i+1]){
                    arr[i]=arr[i+1];
                }
                else{
                    arr[i+1]=arr[i];
                }
                changed=true;
            }
        }
    }

    return true;

}

int main(){
    vector<int> v;
    int n;
    cout<<"Enter the size of vector : ";
    cin>>n;

    cout<<"Enter the vector elements : ";
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    cout<<isPossible(v,n);
}