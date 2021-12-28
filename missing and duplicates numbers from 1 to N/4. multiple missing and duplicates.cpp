#include <bits/stdc++.h>
using namespace std;

//program for finding multiple missing and multiple Duplicates in an unsorted array in O(n) time and O(1) space.

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
    vector<int> miss;
    vector<int> dup;
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
            miss.push_back(i + 1);
            dup.push_back(arr[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Missing Numbers: ";
    for (auto it : miss)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << "Duplicate Numbers: ";
    for (auto it : dup)
    {
        cout << it << " ";
    }

    return 0;
}

/*Input: 8
       2 3 1 8 2 3 5 1
    Output:
    1 2 3 1 5 3 2 8 
    Missing Numbers: 4 6 7 
    Duplicate Numbers: 1 3 2 
    */

// Problem link: https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#

//only drawback is when array is read only then this cannot be applied as here we are modifying the given array.
// swap sort works in O(n) time and O(1) space.
