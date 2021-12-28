class Solution
{
public:
    void solve(string output, int open, int close, vector<string> &res)
    {
        if (open == 0 && close == 0)
        {
            res.push_back(output);
            return;
        }

        else if (open == 0)
        {
            string output1 = output;
            output1.push_back(')');
            solve(output1, open, close - 1, res);
        }

        else if (open < close)
        {
            //two function calls required here
            string output1 = output;
            string output2 = output;
            output1.push_back('(');
            output2.push_back(')');

            solve(output1, open - 1, close, res);
            solve(output2, open, close - 1, res);
        }
        else if (open >= close)
        {
            //only 1 function call required here
            string output1 = output;
            output1.push_back('(');
            solve(output1, open - 1, close, res);
        }

        return;
    }

    vector<string> generateParenthesis(int n)
    {
        int open = n;
        int close = n;
        vector<string> res;
        string output = "";
        solve(output, open, close, res);

        return res;
    }
};