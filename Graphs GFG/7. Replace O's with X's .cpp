// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int row, col;
    bool vis[501][501];

    bool isValid(int x, int y, vector<vector<char>> &mat)
    {
        if (x < 0 || y < 0 || x >= row || y >= col)
        {
            return false;
        }
        if (vis[x][y] == 1 || mat[x][y] == 'X')
        {
            return false;
        }
        return true;
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    void dfs(int x, int y, vector<vector<char>> &mat)
    {
        vis[x][y] = 1;
        mat[x][y] = '#';

        for (int i = 0; i < 4; i++)
        {
            if (isValid(x + dx[i], y + dy[i], mat))
            {
                dfs(x + dx[i], y + dy[i], mat);
            }
        }
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        row = n;
        col = m;
        memset(vis, 0, sizeof(vis));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                {
                    if (mat[i][j] == 'O')
                    {
                        dfs(i, j, mat);
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == '#')
                {
                    mat[i][j] = 'O';
                }
                else
                {
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
} // } Driver Code Ends