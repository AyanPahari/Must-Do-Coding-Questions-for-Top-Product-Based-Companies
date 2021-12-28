// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    string str = "UDLR";
    void solve(int row, int col, int n, vector<vector<int>> m, string output, vector<string> &res, vector<vector<int>> &vis)
    {

        if (row == n - 1 && col == n - 1)
        {
            res.push_back(output);
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int newi = row + dx[i];
            int newj = col + dy[i];
            if (newi >= 0 && newj >= 0 && newi < n && newj < n && !vis[newi][newj] && m[newi][newj] == 1)
            {

                vis[newi][newj] = 1;
                solve(newi, newj, n, m, output + str[i], res, vis);
                vis[newi][newj] = 0;
            }
        }
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<vector<int>> vis(n, vector<int>(n, 0));
        string output;
        vector<string> res;
        if (m[0][0] == 1)
        {
            solve(0, 0, n, m, output, res, vis);
        }
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
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends