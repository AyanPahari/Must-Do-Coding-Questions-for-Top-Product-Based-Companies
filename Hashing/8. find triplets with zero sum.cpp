// { Driver Code Starts
#include <bits/stdc++.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution
{
public:
    //Function to find triplets with zero sum.
    bool findTriplets(int nums[], int n)
    {
        sort(nums, nums + n);
        for (int i = 0; i < n; i++)
        {
            int rem_sum = -nums[i];
            int low = i + 1;
            int high = n - 1;

            while (low < high)
            {
                int sum = nums[low] + nums[high];
                if (rem_sum > sum)
                    low++;
                else if (rem_sum < sum)
                    high--;
                else
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n] = {0};
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        if (obj.findTriplets(arr, n))
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }
    return 0;
} // } Driver Code Ends