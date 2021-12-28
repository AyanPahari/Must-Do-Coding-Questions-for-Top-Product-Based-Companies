// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to detect cycle in a directed graph.
    int col[100001];

    bool detect_cycle(int node, vector<int> adj[])
    {
        col[node] = 1;

        for (auto child : adj[node])
        {
            if (col[child] == 1)
            {
                return true;
            }

            if (col[child] == 0)
            {
                if (detect_cycle(child, adj))
                    return true;
            }
        }
        col[node] = 2;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {
        memset(col, 0, sizeof(col));

        for (int i = 0; i < V; i++)
        {
            if (detect_cycle(i, adj))
            {
                return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends

//here we have three colors, the col 0 indicates white , col 1 indicates black and color 2 indicates black.

/*
WHITE : Vertex is not processed yet. Initially, all vertices are WHITE.

GRAY: Vertex is being processed (DFS for this vertex has started, 
but not finished which means that all descendants (in DFS tree) of this vertex are not processed yet (or this vertex is in the function call stack)

BLACK : Vertex and all its descendants are processed. While doing DFS, 
if an edge is encountered from current vertex to a GRAY vertex, then this edge is back edge and hence there is a cycle.
*/