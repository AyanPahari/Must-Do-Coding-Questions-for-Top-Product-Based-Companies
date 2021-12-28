class Solution
{
public:
    //DP approach
    //time:O(m*n)
    //space:O(m*n)
    int solve(vector<vector<int>> &arr, int i, int j, int m, int n, vector<vector<int>> Grid)
    {

        if (i >= m || j >= n)
            return 0;
        if (i == m - 1 && j == n - 1)
            return 1;
        if (Grid[i][j] == 1)
            return 0; //if any obsticle present then simply return 0
        if (arr[i][j] != -1)
            return arr[i][j];
        return arr[i][j] = (solve(arr, i + 1, j, m, n, Grid) + solve(arr, i, j + 1, m, n, Grid));
    }

    int uniquePathsWithObstacles(vector<vector<int>> &Grid)
    {

        int m = Grid.size();
        int n = Grid[0].size();

        if (Grid[0][0] == 1 || Grid[m - 1][n - 1] == 1)
            return 0; //edge cases
        if (m == 1 && n == 1)
            return 1; //edge cases

        vector<vector<int>> arr(m, vector<int>(n, -1));
        solve(arr, 0, 0, m, n, Grid);
        return arr[0][0];
    }
};