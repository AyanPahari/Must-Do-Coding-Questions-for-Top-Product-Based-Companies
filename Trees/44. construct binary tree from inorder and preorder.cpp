// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
    Node* solve(int& pos,Node*& root, int in[],int pre[],int n, int start, int end, unordered_map<int,int>&mp){
        
        if(start>end) return NULL;
        if(pos>=n) return NULL;
        
        int index=mp[pre[pos]]; //fetching the inorder indexes directly from the map
        
        root=new Node(pre[pos++]);
        root->left=solve(pos,root->left,in,pre,n,start,index-1,mp);
        root->right=solve(pos,root->right,in,pre,n,index+1,end,mp);
        
        return root;
}
    
    Node* buildTree(int in[],int pre[], int n)
    {
        Node* root=NULL;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) mp[in[i]]=i; //storing the indexes of the inorder elements inside a map
        int pos=0;
        solve(pos,root,in,pre,n,0,n-1,mp);
        return root;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends