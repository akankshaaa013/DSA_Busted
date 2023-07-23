#include <bits/stdc++.h>
using namespace std;

void sort0s1s2s(vector<int>& arr) {
        int low=0;
        int mid=0;
        int high=arr.size()-1;

        while(mid<=high){
            if(arr[mid]==0){
                swap(arr[low],arr[mid]);
                low++;
                mid++;
            }
            else if(arr[mid]==1){
                mid++;
            }
            else{
                swap(arr[mid],arr[high]);
                high--;
            }
        }
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

    sort0s1s2s(v);

    for (auto i : v)
    {
        cout << i << "  ";
    }
    
}