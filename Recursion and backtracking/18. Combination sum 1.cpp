class Solution
{
public:
    void solve(int curr, vector<int> output, vector<int> input, int n, vector<vector<int>> &res)
    {
        if (curr == input.size())
        {
            if (n == 0)
                res.push_back(output);

            return;
        }

        if (input[curr] <= n)
        {
            output.push_back(input[curr]);
            solve(curr, output, input, n - input[curr], res);
            output.pop_back();
        }

        solve(curr + 1, output, input, n, res);

        return;
    }

    vector<vector<int>> combinationSum(vector<int> &input, int target)
    {
        vector<vector<int>> res;
        vector<int> output;
        solve(0, output, input, target, res);

        return res;
    }
};