// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int vis[100001];
    int col[100001];

    bool bipartite(vector<int> adj[], int node, int c)
    {
        vis[node] = 1;
        col[node] = c;

        for (auto child : adj[node])
        {
            if (vis[child] == 0)
            {
                if (bipartite(adj, child, c ^ 1) == false)
                    return false;
            }
            else
            {
                if (col[node] == col[child])
                    return false;
            }
        }
        return true;
    }

    bool isBipartite(int V, vector<int> adj[])
    {
        memset(vis, 0, sizeof(vis)); //as multiple test cases can be possible so to clear the prev values
        memset(col, 0, sizeof(col));
        bool flag = true;
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                flag = bipartite(adj, i, 1);
                if (flag == false)
                    break;
            }
        }
        return flag;
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
        bool ans = obj.isBipartite(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
} // } Driver Code Ends