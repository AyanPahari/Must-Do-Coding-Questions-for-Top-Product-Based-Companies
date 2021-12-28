class Solution
{
public:
    void solve(int curr, string output, string digits, unordered_map<char, string> mp, vector<string> &res)
    {
        if (curr == digits.length())
        {
            res.push_back(output);
            return;
        }
        string ch = mp[digits[curr]];
        for (int i = 0; i < ch.length(); i++)
        {
            output.push_back(ch[i]);
            solve(curr + 1, output, digits, mp, res);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        unordered_map<char, string> mp;
        vector<string> res;
        string output;
        if (digits.length() == 0)
            return res;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        solve(0, output, digits, mp, res);

        return res;
    }
};