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

et *solve(char postfix[], int &pos)
{
    if (pos < 0)
        return NULL;
    et *root = new et(postfix[pos--]);
    if (root->value == '+' || root->value == '-' || root->value == '*' || root->value == '/' || root->value == '^')
    {

        root->right = solve(postfix, pos);
        root->left = solve(postfix, pos);
    }
    return root;
}

et *constructTree(char postfix[])
{
    int pos = strlen(postfix) - 1;
    return solve(postfix, pos);
}
