#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{

    int n = prices.size();

    int minStockPrice = INT_MAX;
    int maxProfit = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        minStockPrice = min(minStockPrice, prices[i]);
        maxProfit = max(maxProfit, prices[i] - minStockPrice);
    }
    return maxProfit;
}

int main()
{
    int n;
    cout << "Enter the total days : ";
    cin >> n;

    cout << "Enter the stock prices on i-th day : ";

    vector<int> price;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        price.push_back(x);
    }

    cout << "Max Profit earned is : " << maxProfit(price);
}