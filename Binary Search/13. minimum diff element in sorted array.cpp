#include <iostream>
using namespace std;


int search(int arr[], int n, int k)
{
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (arr[mid] == k)
            return arr[mid];
        else if (arr[mid] > k)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }

        // when the binary search function is over, low and high points to the closest element to the key
    }
    if (abs(arr[low] - k) < abs(arr[high] - k))
    {
        return arr[low];
    }
    else
    {
        return arr[high];
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

// #include <iostream>
// using namespace std;

// int find_floor(int arr[], int n, int k)
// {
//     int res = -1;
//     int low = 0;
//     int high = n - 1;
//     int mid;

//     while (low <= high)
//     {
//         mid = low + (high - low) / 2;

//         if (arr[mid] == k)
//             return mid;
//         else if (arr[mid] > k)
//         {
//             high = mid - 1;
//         }
//         else
//         {
//             res = mid;
//             low = mid + 1;
//         }
//     }
//     return res;
// }

// int find_ceil(int arr[], int n, int k)
// {
//     int res = -1;
//     int low = 0;
//     int high = n - 1;
//     int mid;

//     while (low <= high)
//     {
//         mid = low + (high - low) / 2;

//         if (arr[mid] == k)
//             return mid;
//         else if (arr[mid] > k)
//         {
//             res = mid;
//             high = mid - 1;
//         }
//         else
//         {
//             low = mid + 1;
//         }
//     }
//     return res;
// }

// int main()
// {
//     int n, k;
//     cin >> n >> k;
//     int arr[1001];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     int floor_value = find_floor(arr, n, k);
//     int ceil_value = find_ceil(arr, n, k);

//     if (floor_value != -1 and ceil_value != -1)
//     {
//         if (abs(k - arr[floor_value]) < abs(k - arr[ceil_value]))
//         {
//             cout << arr[floor_value];
//         }
//         else
//         {
//             cout << arr[ceil_value];
//         }
//     }
//     return 0;
// }
