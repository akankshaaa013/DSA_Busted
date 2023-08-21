#include<bits/stdc++.h>
using namespace std;


void subsequences_with_sum_K(vector<int> arr,int k,int sum,int idx,vector<int>& res,vector<vector<int>>& ans){

    if(idx == arr.size()){
        if(sum == k){
            ans.push_back(res);
        }
        return;
    }

    if(sum > k) return;

    res.push_back(arr[idx]);
    sum += arr[idx];

    subsequences_with_sum_K(arr,k,sum,idx+1,res,ans);

    res.pop_back();
    sum -= arr[idx];

    subsequences_with_sum_K(arr,k,sum,idx+1,res,ans);

}

int main()
{

    vector<int> v;
    int n;
    cout << "Enter the size of vector : ";
    cin >> n;

    cout << "Enter the vector elements : ";
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int k;
    cout << "Enter the Target sum : ";
    cin >> k;

    vector<vector<int>> ans;
    vector<int> res;
    
    subsequences_with_sum_K(v, k,0,0,res,ans);

    cout << "Triplet Sets are : \n";
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << "  ";
        }
        cout << endl;
    }
}