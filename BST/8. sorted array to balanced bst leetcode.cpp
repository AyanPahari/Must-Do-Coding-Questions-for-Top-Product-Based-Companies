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
    void create_bst(int low, int high, TreeNode *&root, vector<int> nums)
    {
        if (low > high)
            return;

        int mid = low + (high - low) / 2;

        TreeNode *temp = new TreeNode(nums[mid]);
        root = temp;

        create_bst(low, mid - 1, root->left, nums);
        create_bst(mid + 1, high, root->right, nums);
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        int n = nums.size();

        TreeNode *root = new TreeNode();
        create_bst(0, n - 1, root, nums);

        return root;
    }
};