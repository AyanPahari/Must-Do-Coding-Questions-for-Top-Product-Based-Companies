// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to return the minimum cost of connecting the ropes.

    //idea is same as huffman coding using min heap
    //time:O(nlogn)
    //space:O(n)
    long long minCost(long long arr[], long long n)
    {
        priority_queue<long long, vector<long long>, greater<long long>> minh; //min heap
        for (int i = 0; i < n; i++)
        {
            minh.push(arr[i]);
        }
        long long cost = 0;
        while (minh.size() != 1)
        {
            long long x = minh.top();
            minh.pop();
            long long y = minh.top();
            minh.pop();
            long long z = x + y;
            cost += z;
            minh.push(z);
        }
        return cost;
    }
};

// { Driver Code Starts.

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends