#include <bits/stdc++.h>
using namespace std;

bool isValid(int arr[], int max, int n, int k)
{

    int stu = 1;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum > max)
        {
            stu++;
            sum = arr[i];
        }
    }
    if (stu > k)
    {
        return false;
    }
    return true;
}

int findPages(int arr[], int n, int m)
{
    if (n < m)
    {
        return -1;
    }
    int sum = 0;
    int maxi = 0;
    int res = -1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxi = max(arr[i], maxi);
    }
    int low = maxi;
    int high = sum;
    int mid;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (isValid(arr, mid, n, m) == true)
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << findPages(arr, n, k);
    return 0;
}
