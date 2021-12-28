class Solution
{
public:
    //Problem is same as the longest valid substring problem
    //better approach
    //time:O(n)
    //space:O(n)
    int longestValidParentheses(string s)
    {
        stack<int> st;
        int res = 0;
        st.push(-1);

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                st.push(i);
            else
            {
                st.pop();
                if (!st.empty())
                    res = max(res, i - st.top());
                else
                    st.push(i);
            }
        }
        return res;
    }
};

class Solution
{
public:
    //optimised approach using two counters
    //time:O(n)
    //space:O(1)
    int longestValidParentheses(string s)
    {
        int left = 0, right = 0;
        int res = 0;
        for (int i = 0; i < s.length(); i++)
        { //left to right traversal
            if (s[i] == '(')
                left++;
            if (s[i] == ')')
                right++;
            if (left == right)
                res = max(res, left + right);
            else if (right > left)
                left = 0, right = 0; //if this condition is true then
            //balanced parentheses not possible. so reset the counters
        }
        left = 0, right = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        { //right to left traversal
            if (s[i] == '(')
                left++;
            if (s[i] == ')')
                right++;
            if (left == right)
                res = max(res, left + right);
            else if (right < left)
                left = 0, right = 0; //if this condition is true then
            //balanced parentheses not possible. so reset the counters
        }
        return res;
    }
};