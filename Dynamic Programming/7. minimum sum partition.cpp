#include <bits/stdc++.h>
using namespace std;

vector<int> isSubset(int arr[], int n, int sum)
{
    bool t[n + 1][sum + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
            {
                t[i][j] = false;
            }
            if (j == 0)
            {
                t[i][j] = true;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    vector<int> res;
    for (int i = 0; i < sum + 1; i++)
    {
        if (t[n][i] == true)
        {
            res.push_back(i);
        }
    }
    return res;
}

int minDiffernce(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    vector<int> vec = isSubset(arr, n, sum);
    vector<int> res;

    for (int i = 0; i <= vec.size() / 2; i++)
    {
        res.push_back(vec[i]);
    }

    int mn = INT_MAX;
    for (int i = 0; i < res.size(); i++)
    {
        mn = min(mn, abs(sum - 2 * res[i]));
    }
    return mn;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << minDiffernce(arr, n);
    return 0;
}
