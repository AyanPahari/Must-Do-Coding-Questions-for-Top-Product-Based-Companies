// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    void solve(int one, int zero, int n, string output, vector<string> &res)
    {
        if (n == 0)
        {
            res.push_back(output);
            return;
        }
        if (one == zero)
        {
            string output1 = output;
            output1.push_back('1');
            solve(one + 1, zero, n - 1, output1, res);
        }
        if (one > zero)
        {
            string output1 = output;
            string output2 = output;
            output1.push_back('1');
            output2.push_back('0');

            solve(one + 1, zero, n - 1, output1, res);
            solve(one, zero + 1, n - 1, output2, res);
        }
        return;
    }

    vector<string> NBitBinary(int N)
    {
        int one = 1;
        int zero = 0;
        vector<string> res;
        string output = "";
        output.push_back('1');
        solve(one, zero, N - 1, output, res);

        return res;
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
        Solution ob;
        vector<string> ans = ob.NBitBinary(n);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
} // } Driver Code Ends