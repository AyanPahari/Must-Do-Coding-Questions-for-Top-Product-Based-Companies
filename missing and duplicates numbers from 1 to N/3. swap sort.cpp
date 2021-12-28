#include <bits/stdc++.h>
using namespace std;

//program for finding single missing and single duplicate element.

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int i = 0;
    int miss, dup;
    while (i < n)
    {
        if (arr[i] != arr[arr[i] - 1])
        {
            swap(arr[i], arr[arr[i] - 1]);
        }
        else
        {
            i++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            miss = i + 1;
            dup = arr[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Missing Number: " << miss << endl;
    cout << "Duplicate Number: " << dup << endl;
    return 0;
}

// Problem link: https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#

//swap sort is scalable and it can be used to find multiple missing and multiple duplicates as well.
//only drawback is when array is read only then this cannot be applied as here we are modifying the given array.
// swap sort works in O(n) time and O(1) space.
