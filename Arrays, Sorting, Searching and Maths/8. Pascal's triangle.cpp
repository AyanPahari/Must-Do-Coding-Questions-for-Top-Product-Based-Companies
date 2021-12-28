class Solution
{
public:
    //given a number, return the first n rows of pascals triangle
    //time:O(n^2)
    //space:O(1)
    vector<vector<int>> generate(int n)
    {
        vector<vector<int>> res = {{1}};
        int ans;

        for (int i = 1; i < n; i++)
        {
            ans = 1;
            vector<int> output = {1};
            for (int j = 1; j <= i; j++)
            {
                ans = ans * (i - j + 1) / j;
                output.push_back(ans);
            }
            res.push_back(output);
        }

        return res;
    }
};

class Solution
{
public:
    //Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
    //time:O(n)
    //space:O(1)
    vector<int> getRow(int n)
    {
        vector<int> res = {1};
        long long ans = 1;
        for (int i = 1; i <= n; i++)
        {
            ans = ans * (n - i + 1) / i;
            res.push_back(ans);
        }
        return res;
    }
};

//Given a row and col(0 indexed), return the number in that position of the Pascal's triangle.

//ans: here we just have to return (row-1)c(col-1)