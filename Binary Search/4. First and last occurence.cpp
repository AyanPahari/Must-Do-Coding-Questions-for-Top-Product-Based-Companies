#include <iostream>
using namespace std;

int first_occurance(int n, int arr[], int k)
{
    int low = 0;
    int high = n - 1;
    int mid;
    int result = -1;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (arr[mid] == k)
        {
            result = mid;
            high = mid - 1;
        }
        else if (arr[mid] > k)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return result;
}

int last_occurance(int n, int arr[], int k)
{
    int low = 0;
    int high = n - 1;
    int mid;
    int result = -1;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (arr[mid] == k)
        {
            result = mid;
            low = mid + 1;
        }
        else if (arr[mid] > k)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return result;
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
    int left = first_occurance(n, arr, k);
    int right = last_occurance(n, arr, k);

    cout << "First Occurence :" << left << endl;
    cout << "Last Occurence :" << right << endl;
    return 0;
}
