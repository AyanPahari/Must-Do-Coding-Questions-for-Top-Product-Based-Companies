#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using boost::multiprecision::cpp_int;

using namespace std;
#define ll long long int
#define ul unsigned long int
#define mod 1000000007
#define care                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL), cout.tie(NULL);

int ascending_BS(vector<int> arr, int n, int k)
{
    int low = 0;
    int high = n - 1;
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (arr[mid] == k)
            return mid;
        else if (arr[mid] > k)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int descending_BS(vector<int> arr, int n, int k)
{
    int low = 0;
    int high = n - 1;
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (arr[mid] == k)
            return mid;
        else if (arr[mid] > k)
            low = mid + 1;
        else // just swapped these two conditions
            high = mid - 1;
    }
    return -1;
}

int binary_search(vector<int> arr, int n, int k)
{
    if (n == 1)
    {
        if (arr[0] == k)
            return 0;
        else
            return -1;
    }
    int x;
    if (arr[0] <= arr[1])
    {
        x = ascending_BS(arr, n, k);
    }
    else
    {
        x = descending_BS(arr, n, k);
    }
    return x;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = binary_search(arr, n, k);
    cout << ans;
    return 0;
}