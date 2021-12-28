// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to return the total number of possible unique BST.
    long long solve(vector<long long> &arr, int N)
    {
        if (N == 0 || N == 1)
            return 1;
        if (arr[N] != -1)
            return arr[N];

        long long sum = 0;
        for (int i = 1; i <= N; i++)
        {
            long long res = (solve(arr, i - 1) % 1000000007 * solve(arr, N - i) % 1000000007) % 1000000007;
            sum = ((sum % 1000000007) + (res % 1000000007)) % 1000000007;
        }
        return arr[N] = sum;
    }

    int numTrees(int N)
    {
        vector<long long> arr(N + 1);
        fill(arr.begin(), arr.end(), -1);
        long long x = solve(arr, N);
        return x;
    }
};

// { Driver Code Starts.
#define mod (int)(1e9 + 7)
int main()
{

    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {

        //taking total number of elements
        int n;
        cin >> n;
        Solution ob;
        //calling function numTrees()
        cout << ob.numTrees(n) << "\n";
    }
} // } Driver Code Ends