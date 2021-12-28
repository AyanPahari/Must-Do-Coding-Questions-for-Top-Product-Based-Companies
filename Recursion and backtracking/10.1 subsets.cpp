// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    void solve(vector<int> input, vector<int> output, vector<vector<int>> &res)
    {

        if (input.size() == 0)
        {
            res.push_back(output);
            return;
        }
        vector<int> output1 = output;
        vector<int> output2 = output;

        output2.push_back(input[0]);
        input.erase(input.begin() + 0);

        solve(input, output1, res);
        solve(input, output2, res);

        return;
    }

    vector<vector<int>> subsets(vector<int> &input)
    {
        vector<vector<int>> res;
        vector<int> output;
        solve(input, output, res);
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
        int n, x;
        cin >> n;

        vector<int> array;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            array.push_back(x);
        }

        Solution ob;
        vector<vector<int>> res = ob.subsets(array);

        // Print result
        for (int i = 0; i < res.size(); i++)
        {
            for (int j = 0; j < res[i].size(); j++)
                cout << res[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
} // } Driver Code Ends