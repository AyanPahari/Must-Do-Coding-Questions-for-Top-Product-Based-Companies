// { Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node *node)
{
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node *buildTree(int in[], int post[], int n);

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++)
            cin >> in[i];
        for (int i = 0; i < n; i++)
            cin >> post[i];
        Node *root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.

Node *solve(int &pos, Node *&root, int in[], int post[], int n, int start, int end, unordered_map<int, int> &mp)
{
    if (start > end)
        return NULL;
    if (pos < 0)
        return NULL;

    int index = mp[post[pos]];

    root = new Node(post[pos--]);
    root->right = solve(pos, root->right, in, post, n, index + 1, end, mp);
    root->left = solve(pos, root->left, in, post, n, start, index - 1, mp);

    return root;
}

Node *buildTree(int in[], int post[], int n)
{
    Node *root = NULL;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[in[i]] = i;
    int pos = n - 1;
    solve(pos, root, in, post, n, 0, n - 1, mp);

    return root;
}
