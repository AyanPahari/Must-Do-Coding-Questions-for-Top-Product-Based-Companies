/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void solve(int curr, TreeNode *root, vector<int> output, int targetSum, vector<vector<int>> &res)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            curr += root->val;
            if (curr == targetSum)
            {
                output.push_back(root->val);
                res.push_back(output);
            }
            return;
        }
        output.push_back(root->val);
        solve(curr + root->val, root->left, output, targetSum, res);
        solve(curr + root->val, root->right, output, targetSum, res);
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> output;
        vector<vector<int>> res;
        if (!root)
            return res;
        solve(0, root, output, targetSum, res);

        return res;
    }
};