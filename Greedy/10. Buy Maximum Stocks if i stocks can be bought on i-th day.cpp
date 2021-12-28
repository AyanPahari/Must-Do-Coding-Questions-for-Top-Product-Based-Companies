#include <bits/stdc++.h>
using namespace std;

static bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int buy_max_stocks(int arr[], int n, int k)
{
    vector<pair<int, int>> tup;
    for (int i = 0; i < n; i++)
    {
        tup.push_back({arr[i], i + 1});
    }
    sort(tup.begin(), tup.end(), comp);
    int count = 0;

    for (int i = 0; i < n; i++)
    {

        while (tup[i].first <= k && tup[i].second != 0)
        {
            count++;
            k -= tup[i].first;
            tup[i].second--;
        }
    }
    return count;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << buy_max_stocks(arr, n, k);
    return 0;
}
