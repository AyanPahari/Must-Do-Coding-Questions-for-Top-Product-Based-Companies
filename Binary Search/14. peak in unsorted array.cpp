#include <iostream>
using namespace std;

int findPeakElement(int arr[], int n)
{
    if (n == 1)
    {
        return 0;
    }
    else
    {
        int low = 0;
        int high = n - 1;
        int mid;

        while (low <= high)
        {
            mid = low + (high - low) / 2;

            if (mid >= 1 && mid <= (n - 2))
            {
                if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                    return mid;
                else if (arr[mid + 1] > arr[mid])
                    low = mid + 1;
                else if (arr[mid - 1] > arr[mid])
                    high = mid - 1;
            }
            else if (mid == 0)
            {
                if (arr[0] > arr[1])
                    return 0;
                else
                    return 1;
            }
            else if (mid == (n - 1))
            {
                if (arr[n - 1] > arr[n - 2])
                    return n - 1;
                else
                    return n - 2;
            }
        }
    }
    return 0;
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

    cout << findPeakElement(arr, n);
    return 0;
}
