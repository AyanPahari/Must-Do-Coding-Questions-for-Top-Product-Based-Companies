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
    void solve(TreeNode *root, vector<int> output, vector<vector<int>> &res)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            output.push_back(root->val);
            res.push_back(output);
            return;
        }
        output.push_back(root->val);
        solve(root->left, output, res);
        solve(root->right, output, res);
    }

    int sumNumbers(TreeNode *root)
    {
        vector<int> output;
        vector<vector<int>> res; //this contains all the the paths possible from the leaf node
        solve(root, output, res);
        int sum = 0;

        for (int i = 0; i < res.size(); i++)
        {
            for (int j = 0; j < res[i].size(); j++)
            {
                sum += res[i][j] * pow(10, res[i].size() - j - 1); //converting the vector elements into decimal form and then adding to sum
            }
        }
        return sum;
    }
};