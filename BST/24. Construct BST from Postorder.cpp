// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node *constructTree(int[], int);

void printInorder(Node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int post[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &post[i]);

        Node *root = constructTree(post, n);

        printInorder(root);
        printf("\n");
    }
    return 0;
}
// } Driver Code Ends

/*struct Node
{
	int data;
	Node *left, *right;
};*/

Node *solve(Node *&root, int post[], int size, int &pos, int left, int right)
{
    if (left > right)
        return NULL;
    if (pos <= -1)
        return NULL;
    if (post[pos] < left || post[pos] > right)
        return NULL;

    int temp = post[pos];
    root = new Node(post[pos--]);
    root->right = solve(root->right, post, size, pos, temp + 1, right);
    root->left = solve(root->left, post, size, pos, left, temp - 1);

    return root;
}

Node *constructTree(int post[], int size)
{
    Node *root = new Node(NULL);
    int pos = size - 1;
    solve(root, post, size, pos, INT_MIN, INT_MAX);
    return root;
}