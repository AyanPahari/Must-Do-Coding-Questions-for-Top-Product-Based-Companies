// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int closest3Sum(int arr[], int N, int X)
    {
        sort(arr, arr + N);
        int res = INT_MIN, minDiff = INT_MAX;
        for (int i = 0; i < N; i++)
        {
            int low = i + 1;
            int high = N - 1;
            while (low < high)
            {
                int sum = arr[i] + arr[low] + arr[high];
                int diff = abs(X - sum);

                if (diff == 0)
                    return X;
                else if (sum > X)
                    high--;
                else
                    low++;

                if (diff == minDiff)
                    res = max(res, sum);
                else
                {
                    minDiff = min(minDiff, diff);
                    if (minDiff == diff)
                        res = sum;
                }
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for (int i = 0; i < N; i++)
            cin >> Arr[i];
        int X;
        cin >> X;
        Solution obj;
        cout << obj.closest3Sum(Arr, N, X) << endl;
    }
    return 0;
} // } Driver Code Ends