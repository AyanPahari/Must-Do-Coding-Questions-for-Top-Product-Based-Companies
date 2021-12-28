// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct et
{
    char value;
    et *left, *right;

    et(char x)
    {
        value = x;
        left = right = NULL;
    }
};

bool isOperator(char c)
{
    if (c == '+' || c == '-' ||
        c == '*' || c == '/' ||
        c == '^')
        return true;
    return false;
}

void inorder(et *t)
{
    if (t)
    {
        inorder(t->left);
        printf("%c ", t->value);
        inorder(t->right);
    }
}

et *constructTree(char[]);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        char postfix[25];
        cin >> postfix;
        et *r = constructTree(postfix);
        inorder(r);
        cout << endl;
    }
    return 0;
} // } Driver Code Ends

/*struct et
{
	char value;
	et* left, *right;
};*/

//function to construct expression tree

et *solve(char prefix[], int &pos, int n)
{
    if (pos >= n)
        return NULL;
    et *root = new et(prefix[pos++]);
    if (root->value == '+' || root->value == '-' || root->value == '*' || root->value == '/' || root->value == '^')
    {

        root->left = solve(prefix, pos, n);
        root->right = solve(prefix, pos, n);
    }
    return root;
}

et *constructTree(char prefix[])
{
    int pos = 0;
    int n = strlen(prefix);
    return solve(prefix, pos, n);
}
