#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr,int n){

    for(int i=1;i<n;i++){
    bool swapped = false;
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
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

    bubbleSort(v,n);

    for(auto i:v){
        cout<<i<<"  ";
    }

}