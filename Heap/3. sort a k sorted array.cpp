#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        priority_queue<int, vector<int>, greater<int>> minh;
        vector<int> res;

        for (int i = 0; i < n; i++)
        {
            minh.push(arr[i]);

            if (minh.size() > k)
            {
                int x = minh.top();
                res.push_back(x);
                minh.pop();
            }
        }
        while (!minh.empty())
        {
            int x = minh.top();
            res.push_back(x);
            minh.pop();
        }

        for (auto it : res)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}