class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        res.push_back(nums);
        while (next_permutation(nums.begin(), nums.end())) //method 1
        {
            res.push_back(nums);
        }
        return res;
    }
};

class Solution
{
public:
    void solve(vector<int> freq, vector<int> output, vector<int> input, vector<vector<int>> &res)
    {

        if (output.size() == input.size())
        {
            res.push_back(output);
            return;
        }
        for (int i = 0; i < input.size(); i++)
        {
            if (!freq[i])
            {
                output.push_back(input[i]);
                freq[i] = 1;
                solve(freq, output, input, res);
                freq[i] = 0;
                output.pop_back();
            }
        }
    }
    //method 2
    vector<vector<int>> permute(vector<int> &input)
    {

        int n = input.size();
        vector<vector<int>> res;
        vector<int> output;
        vector<int> freq(n, 0);

        solve(freq, output, input, res);

        return res;
    }
};

class Solution
{
public:
    void solve(int curr, vector<int> input, vector<vector<int>> &res)
    {

        if (curr == input.size())
        {
            res.push_back(input);
            return;
        }
        for (int i = curr; i < input.size(); i++) //method 3
        {
            swap(input[curr], input[i]);
            solve(curr + 1, input, res);
            swap(input[curr], input[i]);
        }
    }

    vector<vector<int>> permute(vector<int> &input)
    {

        vector<vector<int>> res;
        solve(0, input, res);

        return res;
    }
};