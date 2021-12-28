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
    int height(TreeNode *root, bool &flag)
    {
        if (!root || flag == false)
            return 0; //flag==false condition is added because if we get a node that is not balanced we can directly return from there without checking further.
        int L = height(root->left, flag);
        int R = height(root->right, flag);

        if (abs(L - R) > 1)
            flag = false;

        return 1 + max(L, R);
    }
    bool isBalanced(TreeNode *root)
    {
        bool flag = true;
        if (!root)
            return flag;
        height(root, flag);
        return flag;
    }
};