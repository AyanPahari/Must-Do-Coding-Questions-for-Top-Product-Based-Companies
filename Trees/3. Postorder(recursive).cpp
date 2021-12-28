/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    void postorder(TreeNode *root, vector<int> &vec)
    {
        if (!root)
            return;
        postorder(root->left, vec);
        postorder(root->right, vec);
        vec.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> vec;
        postorder(root, vec);
        return vec;
    }
};