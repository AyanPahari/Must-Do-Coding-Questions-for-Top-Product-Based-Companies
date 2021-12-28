#include <iostream>
using namespace std;

int find_pivot(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] > arr[mid + 1])
            return mid + 1;
        else if (arr[mid] < arr[mid + 1])
        {
            if (arr[mid] < arr[n - 1])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    return 0;
}

int binary_search(int arr[], int low, int high, int target)
{
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int search(int nums[], int n, int target)
{

    if (n == 1)
    {
        if (nums[0] == target)
            return 0;
        else
            return -1;
    }
    else
    {

        int index = find_pivot(nums, n, target);

        int left = binary_search(nums, 0, index - 1, target);

        int right = binary_search(nums, index, n - 1, target);

        if (left != -1)
        {
            return left;
        }
        else if (right != -1)
        {
            return right;
        }
        else
        {
            return -1;
        }
    }
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
    cout << search(arr, n, k);
    return 0;
}
