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
    bool isIdentical(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if (!p && q)
            return false;
        if (p && !q)
            return false;

        if (p->val != q->val)
        {
            return false;
        }
        return isIdentical(p->left, q->left) && isIdentical(p->right, q->right);
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *x = q.front();
            q.pop();
            if (x->val == subRoot->val)
            {
                if (isIdentical(x, subRoot))
                    return true;
            }
            if (x->left)
                q.push(x->left);
            if (x->right)
                q.push(x->right);
        }
        return false;
    }
};