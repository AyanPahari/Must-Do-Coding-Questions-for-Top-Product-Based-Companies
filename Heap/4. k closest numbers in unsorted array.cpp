#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, x;
    cin >> n >> k >> x;
    int arr[1001];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    priority_queue<pair<int, int>> maxh;
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        maxh.push({abs(x - arr[i]), arr[i]});

        if (maxh.size() > k)
        {
            maxh.pop();
        }
    }
    while (!maxh.empty())
    {
        res.push_back(maxh.top().second);
        maxh.pop();
    }
    for (auto it : res)
    {
        cout << it << " ";
    }
    return 0;
}