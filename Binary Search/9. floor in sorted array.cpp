#include <iostream>
using namespace std;

int find_floor(int arr[], int n, int k)
{
    int res = -1;
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
        {
            res = mid;
            low = mid + 1;
        }
    }
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[1001];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << find_floor(arr, n, k);
    return 0;
}
