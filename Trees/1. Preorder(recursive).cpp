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
    void preOrder(TreeNode *root, vector<int> &vec)
    {
        if (root == NULL)
            return;
        vec.push_back(root->val);
        preOrder(root->left, vec);
        preOrder(root->right, vec);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> vec;
        preOrder(root, vec);
        return vec;
    }
};