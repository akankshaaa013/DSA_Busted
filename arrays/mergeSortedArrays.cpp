#include <bits/stdc++.h>
using namespace std;

vector<int> mergeSortedArrays(vector<int>& nums1, vector<int>& nums2, int m, int n) {
	int k=m+n-1;
    int i=m-1;
    int j=n-1;
    while(i>=0&&j>=0){
        if(nums2[j]>nums1[i]){
            nums1[k--]=nums2[j--];
        }
        else{
            nums1[k--]=nums1[i--];
        }
    }
    while(i>=0){
        nums1[k--]=nums1[i--];
    }
    while(j>=0){
        nums1[k--]=nums2[j--];
    }
    
    return nums1;
}

int main(){

    vector<int> nums1;
    vector<int> nums2;
    int m,n;

    cout<<"Enter the size of vector 1 : ";
    cin>>m;
    cout<<"Enter the vector elements : ";
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        nums1.push_back(a);
    }

    cout<<"Enter the size of vector 2 : ";
    cin>>n;
    cout<<"Enter the vector elements : ";

    for(int i=0;i<n;i++){
        nums1.push_back(0);
    }
    
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        nums2.push_back(a);
    }
    
    vector<int> v = mergeSortedArrays(nums1,nums2,m,n);
    for(auto i:v){
        cout<<i<<"  ";
    }
}