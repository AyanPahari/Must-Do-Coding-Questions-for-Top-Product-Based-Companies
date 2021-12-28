// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        sort(a, a + n); //sorting so that the minimum elements will come in front
        for (int i = 0; i < n; i++)
        {
            if (k != 0 && a[i] < 0) //making neg no. positive till k!=0. As the neg no. with highest abs value are in front, this will ensure that sum is maximized
            {
                a[i] = abs(a[i]);
                k--;
            }
        }
        long long mini = INT_MAX;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, a[i]); //calc the minimum element in the array
            sum += a[i];
        }
        if (k % 2 == 0) //here either k==0 or k is a multiple of 2. in either of the cases no need to do anything
            return sum;
        else                      //as we have to make 1 element neg, so making the least no. neg so it does not affect the maximum sum that much
            sum = sum - 2 * mini; //as sum is already having the minimum element, so we decrease it by 2*mini.

        return sum;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        long long int a[n + 5];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.maximizeSum(a, n, k) << endl;
    }

    return 0;
} // } Driver Code Ends