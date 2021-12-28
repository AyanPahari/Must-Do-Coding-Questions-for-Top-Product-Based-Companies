#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
class myComparator
{
public:
    int operator()(p &p1, p &p2)
    {

        if (p1.first < p2.first)
            return true;
        else if (p1.first > p2.first)
            return false;
        else
        {
            if (p1.second > p2.second)
                return true;
            else
                return false;
        }
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            arr[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        unordered_map<int, int> mp;
        priority_queue<p, vector<p>, myComparator> maxh;

        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            maxh.push({i->second, i->first});
        }
        vector<int> res;
        while (!maxh.empty())
        {
            int x = maxh.top().second;
            int freq = maxh.top().first;
            while (freq--)
            {
                res.push_back(x);
            }
            maxh.pop();
        }
        for (auto it : res)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}