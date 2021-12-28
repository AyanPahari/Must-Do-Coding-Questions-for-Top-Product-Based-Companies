int height(struct Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int left = height(node->left);
    int right = height(node->right);
    return 1 + max(left, right);
}