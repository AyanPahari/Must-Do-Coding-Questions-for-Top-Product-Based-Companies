// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to detect cycle in an undirected graph.

    bool dfs(vector<int> adj[], int node, int par, vector<int> &vis)
    {
        vis[node] = 1;

        for (auto child : adj[node])
        {
            if (vis[child] == 0)
            {
                if (dfs(adj, child, node, vis) == true)
                {
                    return true;
                }
            }
            else
            {
                if (child != par)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                if (dfs(adj, i, -1, vis) == true)
                {
                    return 1;
                }
            }
        }
        return 0;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
} // } Driver Code Ends