class Solution
{
public:
    void solve(int curr, vector<int> output, vector<int> input, vector<vector<int>> &res)
    {

        res.push_back(output);

        for (int i = curr; i < input.size(); i++)
        {
            if (i > curr && input[i] == input[i - 1])
                continue;
            output.push_back(input[i]);
            solve(i + 1, output, input, res);
            output.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &input)
    {
        vector<vector<int>> res;
        vector<int> output;
        sort(input.begin(), input.end());
        solve(0, output, input, res);

        return res;
    }
};