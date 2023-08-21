#include <bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int>& A, int k) {
        
       int low = 0;
       int high = A.size()-1 ;
       int mid;
       while (low <= high) {
            mid = (low + high) / 2;
            if (A[mid] - (1 + mid) < k)  
            //A[m]-(m+1)   --> This gives no. of missing numbers before m'th index
                low = mid + 1;
            else
                high = mid-1;
        }
        return low + k;
    }

int main()
{

    int n;
    vector<int> arr;
    cout << "Enter the size of the array : ";
    cin >> n;
    cout << "Enter the array elements : ";
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    int k;
    cout<<"Enter the k-th positive integer u want to find : ";
    cin>>k;


    cout<<k<<"-th "<<"Missing Integer is : "<<findKthPositive(arr,k)<<endl;
}