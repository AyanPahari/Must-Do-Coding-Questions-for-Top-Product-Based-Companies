#include <iostream>
using namespace std;

int search(int arr[], int low, int high, int k)
{
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
            low = mid + 1;
        }
    }
    return -1;
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
    int low = 0;
    int high = 1;

    while (arr[high] < k)
    {
        low = high;
        high *= 2;
    }
    cout << search(arr, low, high, k);
    return 0;
}
