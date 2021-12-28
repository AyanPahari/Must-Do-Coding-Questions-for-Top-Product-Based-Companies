class Solution
{
public:
    void solve(vector<int> input, vector<int> output, vector<vector<int>> &res)
    {

        if (input.size() == 0)
        {
            if (find(res.begin(), res.end(), output) == res.end())
            {
                res.push_back(output);
            }
            return;
        }
        vector<int> output1 = output;
        vector<int> output2 = output;

        output2.push_back(input[0]);
        input.erase(input.begin() + 0);

        solve(input, output1, res);
        solve(input, output2, res);

        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int> &input)
    {
        vector<vector<int>> res;
        vector<int> output;
        sort(input.begin(), input.end()); //sorting is important otherwise it will consider [1,4] and [4,1] different but they are same

        solve(input, output, res);

        return res;
    }
};