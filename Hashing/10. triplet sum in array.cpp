// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to find if there exists a triplet in the
    //array A[] which sums up to X.
    bool find3Numbers(int nums[], int n, int X)
    {
        //Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.
        sort(nums, nums + n);
        for (int i = 0; i < n; i++)
        {
            int rem_sum = X - nums[i];
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
    int T;
    cin >> T;
    while (T--)
    {
        int n, X;
        cin >> n >> X;
        int i, A[n];
        for (i = 0; i < n; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.find3Numbers(A, n, X) << endl;
    }
}
// } Driver Code Ends