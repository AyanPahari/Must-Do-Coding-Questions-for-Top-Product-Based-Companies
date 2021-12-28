#include <iostream>
using namespace std;

int findMin(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }
    else
    {
        int low = 0;
        int high = n - 1;
        int mid;

        while (low <= high)
        {
            mid = low + (high - low) / 2;

            if (arr[mid] > arr[mid + 1])
                return arr[mid + 1];
            else if (arr[mid] < arr[mid + 1])
            {
                if (arr[mid] < arr[n - 1])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }
    }
    return arr[0];
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
    int ans = findMin(arr, n);
    cout << ans;
    return 0;
}
