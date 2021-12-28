#include <bits/stdc++.h>
using namespace std;

vector<long long> NSL(long long arr[], int n)
{
    stack<pair<long long, long long>> s;
    vector<long long> res;
    for (int i = 0; i < n; i++)
    {
        if (s.size() == 0)
        {
            res.push_back(-1);
        }
        else if (s.size() > 0 and s.top().first < arr[i])
        {
            res.push_back(s.top().second);
        }
        else if (s.size() > 0 and s.top().first >= arr[i])
        {
            while (s.size() > 0 and s.top().first >= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                res.push_back(-1);
            }
            else if (s.top().first < arr[i])
            {
                res.push_back(s.top().second);
            }
        }
        s.push({arr[i], i});
    }
    return res;
}

vector<long long> NSR(long long arr[], int n)
{
    stack<pair<long long, long long>> s;
    vector<long long> res;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.size() == 0)
        {
            res.push_back(n);
        }
        else if (s.size() > 0 and s.top().first < arr[i])
        {
            res.push_back(s.top().second);
        }
        else if (s.size() > 0 and s.top().first >= arr[i])
        {
            while (s.size() > 0 and s.top().first >= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                res.push_back(n);
            }
            else if (s.top().first < arr[i])
            {
                res.push_back(s.top().second);
            }
        }
        s.push({arr[i], i});
    }
    reverse(res.begin(), res.end());
    return res;
}

long long getMaxArea(long long arr[], int n)
{
    vector<long long> left = NSL(arr, n);
    vector<long long> right = NSR(arr, n);
    vector<long long> res(n, 0); //whenever we use a vector for indexing like an array always define its size,
                                 //otherwise it will give segmentation fault. if vector is used just for pushback
                                 //operation then no need to define the size.

    for (int i = 0; i < n; i++)
    {
        res[i] = (arr[i]) * (right[i] - left[i] - 1);
    }
    return *max_element(res.begin(), res.end());
}

int main()
{
    int n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << getMaxArea(arr, n);
    return 0;
}
