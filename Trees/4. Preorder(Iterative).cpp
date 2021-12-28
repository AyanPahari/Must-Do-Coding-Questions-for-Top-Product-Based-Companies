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
    void helper(TreeNode *root, stack<TreeNode *> &s, vector<int> &res)
    {
        TreeNode *temp = root;
        while (temp)
        {
            s.push(temp);
            res.push_back(temp->val);
            temp = temp->left;
        }
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> s;
        vector<int> res;
        helper(root, s, res);
        while (!s.empty())
        {
            TreeNode *temp = s.top();
            s.pop();
            helper(temp->right, s, res);
        }
        return res;
    }
};