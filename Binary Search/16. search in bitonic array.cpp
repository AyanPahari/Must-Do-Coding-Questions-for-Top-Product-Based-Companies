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

int ascending_BS(int arr[], int low, int high, int k)
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
            low = mid + 1;
    }
    return -1;
}

int descending_BS(int arr[], int low, int high, int k)
{
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == k)
            return mid;
        else if (arr[mid] > k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int find(int arr[], int n, int k)
{
    // bitonic array can be divided into two sorted arrays, one ascending and one descending.
    //we just have to find the index of the split.
    int index = peakIndexInMountainArray(arr, n);
    int left = ascending_BS(arr, 0, index - 1, k);
    int right = descending_BS(arr, index, n - 1, k);

    if (left != -1)
    {
        return left;
    }
    else if (right != -1)
    {
        return right;
    }
    else
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

    cout << find(arr, n, k);
    return 0;
}
