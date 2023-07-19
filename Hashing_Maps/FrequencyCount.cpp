#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<char, int> count;

    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    vector<char> nums;
    cout << "Enter the vector elements (char) : ";

    for (int i = 0; i < n; i++)
    {
        char a;
        cin >> a;
        nums.push_back(a);
        count[a]++;
    }

    for (auto m : count)
    {
        cout << m.first << "    " << m.second << endl;
    }
}