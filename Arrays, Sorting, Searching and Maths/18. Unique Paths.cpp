class Solution
{
public:
    //recursive approach with exponential time and space complexity. So will give TLE
    int solve(int i, int j, int des_i, int des_j)
    {
        if (i >= des_i || j >= des_j)
            return 0;
        if (i == des_i - 1 && j == des_j - 1)
            return 1;
        return solve(i + 1, j, des_i, des_j) + solve(i, j + 1, des_i, des_j);
    }

    int uniquePaths(int m, int n)
    {
        return solve(0, 0, m, n);
    }
};

class Solution
{
public:
    //Applying DP to the earlier recursive approach
    //time:O(m*n)
    //space:O(m*n)
    int solve(vector<vector<int>> &arr, int i, int j, int des_i, int des_j)
    {

        if (i >= des_i || j >= des_j)
            return 0;
        if (i == des_i - 1 && j == des_j - 1)
            return 1;
        if (arr[i][j] != -1)
            return arr[i][j];
        return arr[i][j] = (solve(arr, i + 1, j, des_i, des_j) + solve(arr, i, j + 1, des_i, des_j));
    }

    int uniquePaths(int m, int n)
    {
        if (m == 1 && n == 1)
            return 1;
        vector<vector<int>> arr(m, vector<int>(n, -1));
        solve(arr, 0, 0, m, n);
        return arr[0][0];
    }
};

class Solution
{
public:
    //using combinotrics
    //time:O(n-1) or O(m-1)
    //space: O(1)
    int uniquePaths(int m, int n)
    {
        int x = m + n - 2;
        int y = m - 1;
        long long res = 1;
        for (int i = 1; i <= y; i++)
        {
            res = res * (x - y + i) / i;
        }
        return res;
    }
};