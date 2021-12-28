// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void solve(string input, string output, vector<string> &res)
    {
        if (input.length() == 0)
        {
            res.push_back(output);
            return;
        }
        string output1 = output + " " + input[0];
        string output2 = output + input[0];

        input.erase(input.begin() + 0);

        solve(input, output1, res);
        solve(input, output2, res);

        return;
    }

    vector<string> permutation(string input)
    {
        vector<string> res;
        string output = "";
        output.push_back(input[0]);
        input.erase(input.begin() + 0);
        solve(input, output, res);
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
        string S;
        cin >> S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << "(" << ans[i] << ")";
        }
        cout << endl;
    }
}
// } Driver Code Ends