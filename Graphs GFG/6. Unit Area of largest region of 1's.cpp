// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find unit area of the largest region of 1s.
    bool vis[501][501];
    int row, col;
    int count;

    bool isValid(int x, int y, vector<vector<int>> &grid)
    {
        if (x < 0 || y < 0 || x > row - 1 || y > col - 1)
            return false;
        if (vis[x][y] == 1 || grid[x][y] == 0)
            return false;

        return true;
    }

    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dfs(int x, int y, vector<vector<int>> &grid)
    {
        vis[x][y] = 1;
        count++;

        for (int i = 0; i < 8; i++)
        {
            if (isValid(x + dx[i], y + dy[i], grid))
                dfs(x + dx[i], y + dy[i], grid);
        }
        return count;
    }

    int findMaxArea(vector<vector<int>> &grid)
    {
        memset(vis, 0, sizeof(vis));
        row = grid.size();
        col = grid[0].size();
        int ans = 0;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (vis[i][j] == 0 && grid[i][j] == 1)
                {
                    count = 0;
                    ans = max(ans, dfs(i, j, grid));
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.findMaxArea(grid);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends