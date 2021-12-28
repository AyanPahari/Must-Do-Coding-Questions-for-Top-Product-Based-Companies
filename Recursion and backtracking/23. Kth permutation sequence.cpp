/*class Solution
{
public:
    //using the bulitin next_permutation function
    string getPermutation(int n, int k)
    {
        string res = "";
        for (int i = 1; i <= n; i++)
        {
            res += to_string(i);
        }
        while (--k)
        {
            next_permutation(res.begin(), res.end());
        }
        return res;
    }
};
*/
class Solution
{
public:
    int factorial(int n)
    {
        return (n == 0) || (n == 1) ? 1 : n * factorial(n - 1);
    }

    void solve(string input, int n, int k, string &res)
    {
        if (n == 1)
        {
            res.push_back(input[0]);
            return;
        }

        int fact = factorial(n - 1);
        int q = k / fact;
        res.push_back(input[q]);
        input.erase(input.begin() + q);
        solve(input, n - 1, k % fact, res);
    }

    string getPermutation(int n, int k)
    {
        string input = "";
        string res;
        for (int i = 1; i <= n; i++)
        {
            input += to_string(i);
        }
        solve(input, n, k - 1, res);
        return res;
    }
};