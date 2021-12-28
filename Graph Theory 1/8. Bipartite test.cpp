#include <bits/stdc++.h>
using namespace std;

//check if graph bipartite or not.

bool bipartite(int i, int c, vector<int> &vis, vector<int> &col, vector<vector<int>> adj)
{

    col[i] = c;
    vis[i] = 1;

    for (auto nb : adj[i])
    {
        if (vis[nb] == 0) //if the neighbour is not visited
        {
            if (bipartite(nb, c ^ 1, vis, col, adj) == false)
                return false;
        }
        else
        {
            if (col[nb] == col[i]) //if the neighbour is already visited
                return false;
        }
    }
    return true;
}

int main()
{
    int T;
    cin >> T;
    int count = T;
    while (T--)
    {
        int n, e;
        cin >> n >> e;
        vector<vector<int>> adj;
        adj.resize(n + 1);
        while (e--)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n + 1, 0);
        vector<int> col(n + 1, 0);

        bool bi = true;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                bi = bipartite(i, 0, vis, col, adj); //this will work even when the graph has multiple connected components.
                if (bi == false)
                    break;
            }
        }

        if (bi == false)
        {
            cout << "graph not bipartite";
            cout << endl;
        }
        else
        {
            cout << "graph is bipartite";
            cout << endl;
        }
    }

    return 0;
}