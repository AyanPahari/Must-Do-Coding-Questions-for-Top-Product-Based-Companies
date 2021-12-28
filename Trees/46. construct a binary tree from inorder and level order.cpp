// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(int inorder[], int levelOrder[], int iStart, int iEnd, int n);
void printPreorder(Node *node)
{
    if (node == NULL)
        return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int in[n], level[n];
        for (int i = 0; i < n; i++)
        {
            cin >> in[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> level[i];
        }
        Node *root = NULL;
        root = buildTree(in, level, 0, n - 1, n);
        printPreorder(root);
        cout << endl;
    }
    return 0;
} // } Driver Code Ends

/*Complete the function below
Node is as follows:
struct Node
{
    int key;
    struct Node* left, *right;
};
*/

Node *solve(int inorder[], int levelOrder[], int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;

    Node *root = new Node(inorder[mid]);
    root->left = solve(inorder, levelOrder, start, mid - 1);
    root->right = solve(inorder, levelOrder, mid + 1, end);

    return root;
}

Node *buildTree(int inorder[], int levelOrder[], int iStart, int iEnd, int n)
{
    Node *root = solve(inorder, levelOrder, 0, n - 1);
    return root;
}