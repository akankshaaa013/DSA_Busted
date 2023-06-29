#include<bits/stdc++.h>
using namespace std;

//*Recursive Function To Calculate the Sum of an Array 
int Sum_of_Array(int arr[],int size,int sum){
    if(size==0) return sum;

    return Sum_of_Array(arr+1,size-1,sum+arr[0]);
}


//*Recursive Function To Check if an Array is Sorted or Not ? 
bool isSorted(int* arr,int size){
    if(size==0||size==1) return true;
    if(arr[0]>arr[1]) return false;

    return isSorted(arr+1,size-1);
}

//*Recursive function to find an element in an array using Linear_Search().
int linear_Search(int *arr,int size,int key,int n){
    if(arr[0]==key) return (n-size);

    if(size==0) return -1;

    return linear_Search(arr+1,size-1,key,n);
}

//*Recursive function to find an element in an array using Binary_Search().
int Binary_Search(int* arr,int s,int e,int key){
    if(s>e) return -1;

    int mid = s+(e-s)/2;

    if(arr[mid]==key) return mid;

    if(arr[mid]<key) Binary_Search(arr,mid+1,e,key);
    else Binary_Search(arr,s,mid-1,key);
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

    int key;
    cout<<"Enter the Key Element You want to Search : ";
    cin>>key;
    cout<<endl;

    if(isSorted(arr,n)){ 
        cout<<"Array is Sorted :) ";
        int B_index = Binary_Search(arr,0,n-1,key);

        if(B_index !=-1){
            cout<<endl<<"Element Found at the position : "<<B_index<<endl;
        }
        else cout<<endl<<"Element Not Found :("<<endl;
    }
    else{
        cout<<"Array is not Sorted :( ";
        int index = linear_Search(arr,n,key,n);
        if(index !=-1){
            cout<<endl<<"Element Found at the position : "<<index<<endl;
        }
        else cout<<endl<<"Element Not Found :("<<endl;
    }

    cout<<"Array Sum is : "<<Sum_of_Array(arr,n,0)<<endl;

}