class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = 0;
        int j = s.length() - 1;
        while (i < j)
        {
            if (s[i++] != s[j--])
            {
                return false;
            }
        }
        return true;
    }

    void solve(int curr, vector<string> output, string input, vector<vector<string>> &res)
    {

        if (curr == input.length())
        {
            res.push_back(output);
            return;
        }

        for (int i = curr; i < input.length(); i++)
        {

            if (isPalindrome(input.substr(curr, i - curr + 1)))
            {

                output.push_back(input.substr(curr, i - curr + 1));
                solve(i + 1, output, input, res);
                output.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string input)
    {
        vector<vector<string>> res;
        vector<string> output;
        solve(0, output, input, res);

        return res;
    }
};