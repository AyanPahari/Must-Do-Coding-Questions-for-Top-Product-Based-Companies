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
    void inorder(TreeNode *root, vector<int> &vec)
    {
        if (!root)
            return;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> vec;
        inorder(root, vec);
        return vec;
    }
};