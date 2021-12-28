class Solution
{
public:
    void solve(int curr, vector<int> output, vector<int> input, int target, vector<vector<int>> &res)
    {
        if (target == 0)
        {
            res.push_back(output);
            return;
        }
        for (int i = curr; i < input.size(); i++)
        {
            if (i > curr && input[i] == input[i - 1])
                continue;
            if (input[i] > target)
                break;

            output.push_back(input[i]);
            solve(i + 1, output, input, target - input[i], res);
            output.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &input, int target)
    {
        vector<vector<int>> res;
        vector<int> output;
        sort(input.begin(), input.end());
        solve(0, output, input, target, res);

        return res;
    }
};