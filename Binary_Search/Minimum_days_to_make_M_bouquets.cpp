#include <bits/stdc++.h>
using namespace std;

//* T.C -> O(n)
int largestElement(vector<int> arr)
{
    int max = INT_MIN;

    for (auto i : arr)
    {
        if (i > max)
        {
            max = i;
        }
    }
    return max;
}

//* T.C -> O(n)
int smallestElement(vector<int> arr)
{
    int min = INT_MAX;

    for (auto i : arr)
    {
        if (i < min)
        {
            min = i;
        }
    }
    return min;
}

//* T.C -> O(n)
bool totalBouquetsPossible(vector<int> &arr, int mid, int b, int f)
{

    int cnt = 0;
    int bqcnt = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= mid)
        {
            cnt += 1;
        }
        else
        {
            int x = (cnt / f);
            bqcnt += x;
            cnt = 0;
        }
    }

    bqcnt += (cnt / f);

    if (bqcnt == b)
    {
        return true;
    }
    return false;
}

//* T.C -> O(log (max-min+1))
int Minimum_days_to_make_M_bouquets(vector<int> &arr, int bouquets, int flowers)
{

    int low = smallestElement(arr);
    int high = largestElement(arr);

    int n = arr.size();

    if ((bouquets * flowers) > n)
        return -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        cout << "mid --> " << mid << endl;

        if (totalBouquetsPossible(arr, mid, bouquets, flowers))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}

//* Total Time Complexity is : O(n + n + n.log (max-min+1)) == O(2n + nlog n)

int main()
{
    int n;
    vector<int> arr;
    cout << "Enter the Total no. of roses : ";
    cin >> n;
    cout << "Enter the Days in which the i-th rose will be blooming : ";
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    int bouquets1;
    cout << "Enter the No. of Bouquets u want to make: ";
    cin >> bouquets1;

    int flowers1;
    cout << "Enter the roses per bouquets : ";
    cin >> flowers1;

    int ans = Minimum_days_to_make_M_bouquets(arr, bouquets1, flowers1);

    if (ans < 0)
    {
        cout << "Less no. of flowers :( " << endl;
    }
    else
    {
        cout << "Minimum No. of Days required to make n bouqets is : " << ans << endl;
    }
}