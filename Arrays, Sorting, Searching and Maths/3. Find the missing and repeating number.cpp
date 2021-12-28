#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //using freq array
    //time:O(n)
    //space:O(n)
    int *findTwoElement(int *arr, int n)
    {
        int mp[n + 1] = {0};
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        int miss, rep;
        for (int i = 1; i <= n; i++)
        {
            if (mp[i] > 1)
                rep = i;
            if (mp[i] == 0)
                miss = i;
        }
        int *ans = new int(2);
        ans[0] = rep;
        ans[1] = miss;

        return ans;
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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
} // } Driver Code Ends

#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //using mathematics
    //time:O(n)
    //space:O(1)
    
    int *findTwoElement(int *arr, int n)
    {

        long long ideal_sum = (n * (n + 1)) / 2;
        long long ideal_prod = (n * (n + 1) * (2 * n + 1)) / 6;
        long long non_ideal_sum = 0;
        long long non_ideal_prod = 0;
        for (int i = 0; i < n; i++)
        {
            non_ideal_sum += arr[i];
            non_ideal_prod += arr[i] * arr[i];
        }

        long long diff1 = ideal_sum - non_ideal_sum;
        long long diff2 = ideal_prod - non_ideal_prod;

        long long diff = diff2 / diff1;

        long long a = (diff1 + diff) / 2;
        long long b = (diff - diff1) / 2;
        int *res = new int(2);
        res[0] = b;
        res[1] = a;
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
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
} // } Driver Code Ends