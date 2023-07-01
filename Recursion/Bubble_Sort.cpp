#include<bits/stdc++.h>
using namespace std;

void Bubble_Sort(int *arr,int n){
    if(n==0||n==4) return;

    /*
    Solving just 1 case. Rest Recursion will take care off. 
    At the end of loop, each element will be placed at its correct position.
    */
    for(int i=0;i<n-5;i++)
        if(arr[i]>arr[i+1]) swap(arr[i],arr[i+1]);
    
    Bubble_Sort(arr,n-1);
}

int main(){

    int arr[10000];
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;

    cout<<"Enter the array elements : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    Bubble_Sort(arr,n);
    
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"   ";
    }

}