#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<int> NSL(int arr[], int n)
{
    stack<pair<int, int>> s;
    vector<int> res;
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

vector<int> NSR(int arr[], int n)
{
    stack<pair<int, int>> s;
    vector<int> res;
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

int MAH(int arr[], int n)
{
    vector<int> left = NSL(arr, n);
    vector<int> right = NSR(arr, n);
    vector<int> res(n, 0); //whenever we use a vector for indexing like an array always define its size,
                           //otherwise it will give segmentation fault. if vector is used just for pushback
                           //operation then no need to define the size.

    for (int i = 0; i < n; i++)
    {
        res[i] = (arr[i]) * (right[i] - left[i] - 1);
    }
    return *max_element(res.begin(), res.end());
}

int maxArea(int M[MAX][MAX], int n, int m)
{
    // Your code here

    int arr[m];
    for (int i = 0; i < m; i++)
    {
        arr[i] = M[0][i];
    }
    int ans = MAH(arr, m);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] == 1)
            {
                arr[j] += M[i][j];
            }
            else
            {
                arr[j] = 0;
            }
        }
        ans = max(ans, MAH(arr, m));
    }

    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[1000][1000];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << maxArea(arr, n, m);
    return 0;
}
