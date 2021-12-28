// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void solve(int curr, int sum, vector<int> input, vector<int> &res)
    {
        if (curr == input.size())
        {
            res.push_back(sum);
            return;
        }
        solve(curr + 1, sum + input[curr], input, res);
        solve(curr + 1, sum, input, res);
    }

    vector<int> subsetSums(vector<int> input, int N)
    {
        vector<int> res;
        solve(0, 0, input, res);
        sort(res.begin(), res.end());
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
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        for (auto sum : ans)
        {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends