#include <iostream>
using namespace std;

int modified_BS(int arr[], int n, int k)
{
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (arr[mid] == k)
            return mid;
        else if ((mid - 1) >= low and arr[mid - 1] == k)
            return mid - 1;
        else if ((mid + 1) <= high and arr[mid + 1] == k)
            return mid + 1;

        else if (arr[mid] > k)
            high = mid - 2;
        else
            low = mid + 2;
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
    cout << modified_BS(arr, n, k);
    return 0;
}
