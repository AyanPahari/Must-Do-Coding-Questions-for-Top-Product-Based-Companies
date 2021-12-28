class Solution
{
public:
    void solve(string input, string output, vector<string> &res)
    {

        if (input.length() == 0)
        {
            res.push_back(output);
            return;
        }

        if (isalpha(input[0]))
        {
            string output1 = output;
            string output2 = output;

            output1.push_back(tolower(input[0]));
            output2.push_back(toupper(input[0]));
            input.erase(input.begin() + 0);

            solve(input, output1, res);
            solve(input, output2, res);
        }

        else
        {
            string output1 = output;
            output1.push_back(input[0]);
            input.erase(input.begin() + 0);

            solve(input, output1, res);
        }
        return;
    }

    vector<string> letterCasePermutation(string input)
    {
        string output = "";
        vector<string> res;
        solve(input, output, res);

        return res;
    }
};