#include<bits/stdc++.h>
using namespace std;

void sortZeroesAndOne(int input[], int size)
{
    int i=0;
    int j =size-1;

    while(i<j){
        if(input[i]>input[j]){
            swap(input[i++],input[j--]);
        }
        else if(input[i]==0){
            i++;
        }
        else{
            j--;
        }
    }
}

int main(){
    
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    int arr[10000];
    cout<<"Enter the array elements : ";

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sortZeroesAndOne(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
        }
}