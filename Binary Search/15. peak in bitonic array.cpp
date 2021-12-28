#include <iostream>
using namespace std;

int peakIndexInMountainArray(int arr[], int n)
{
    int res = -1;
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] > arr[mid + 1])
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    int arr[1001];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << peakIndexInMountainArray(arr, n);
    return 0;
}
