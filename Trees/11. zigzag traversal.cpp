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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;

        queue<TreeNode *> q;
        int len;
        q.push(root);

        while (!q.empty())
        {
            len = q.size();
            vector<int> ans;

            for (int i = 0; i < len; i++)
            {
                TreeNode *x = q.front();
                ans.push_back(x->val);
                q.pop();

                if (x->left)
                    q.push(x->left);
                if (x->right)
                    q.push(x->right);
            }
            res.push_back(ans);
        }
        for (int i = 0; i < res.size(); i++)
        {
            if (i % 2 != 0)
            {
                reverse(res[i].begin(), res[i].end());
            }
        }
        return res;
    }
};