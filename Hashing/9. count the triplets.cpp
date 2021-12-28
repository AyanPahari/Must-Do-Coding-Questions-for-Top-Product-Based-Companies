// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
    //Given an array of distinct integers. The task is to count all the triplets such that sum of two elements equals the third element.
public:
    int countTriplet(int arr[], int n)
    {
        //approach is similar to count the number of triplets except that here we fix
        //the largest element and see if the sum of remaining two elements will be equal to
        //the fixed one
        sort(arr, arr + n);
        int count = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int low = 0;
            int high = i - 1;
            while (low < high)
            {
                int sum = arr[low] + arr[high];
                if (sum == arr[i])
                {
                    count++;
                    low++;
                    high--;
                }
                else if (sum > arr[i])
                    high--;
                else
                    low++;
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";
    }

    return 0;
} // } Driver Code Ends