#include <bits/stdc++.h>
using namespace std;

vector<int> maxl(int arr[], int n)
{
    vector<int> res(n, 0);
    res[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        res[i] = max(arr[i], res[i - 1]);
    }
    return res;
}

vector<int> maxr(int arr[], int n)
{
    vector<int> res(n, 0);
    res[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        res[i] = max(arr[i], res[i + 1]);
    }
    return res;
}

int trappingWater(int arr[], int n)
{
    // Code here
    vector<int> res(n, 0);

    vector<int> left = maxl(arr, n);
    vector<int> right = maxr(arr, n);

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        res[i] = min(left[i], right[i]) - arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        sum += res[i];
    }
    return sum;
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
    cout << trappingWater(arr, n);
    return 0;
}


//in this problem we don't use the concepts of NGR and NGR. Instead we look for the absolute 
//greater value that is in the left and right of a particular element.