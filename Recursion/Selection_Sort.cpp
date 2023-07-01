#include<bits/stdc++.h>
using namespace std;

void Selection_Sort(int *arr,int n){
    if(n==0||n==1) return;

    int minIndex = 0;
    for(int j=1;j<n;j++){
        if(arr[j]<arr[minIndex]) minIndex=j;
    }

    swap(arr[minIndex],arr[0]);
    Selection_Sort(arr+1,n-1);
    
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

    Selection_Sort(arr,n);
    
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"   ";
    }

}