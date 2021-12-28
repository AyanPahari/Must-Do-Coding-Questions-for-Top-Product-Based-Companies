#include <bits/stdc++.h>
using namespace std;

//check if graph contains cycle or not.

bool detect_cycle(int i, int par, vector<int> &vis, vector<vector<int>> adj)
{

    vis[i] = 1;
    for (auto child : adj[i])
    {
        if (vis[child] == 0)
        {
            if (detect_cycle(child, i, vis, adj) == true)
            {
                return true;
            }
        }
        else
        {
            if (child != par) // to detect back edge
            {
                return true;
            }
        }
    }
    return false;
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

        bool bi = false;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                bi = detect_cycle(i, 0, vis, adj); //this will work even when the graph has multiple connected components.
                if (bi == true)
                    break;
            }
        }

        if (bi == true)
        {
            cout << "graph contains cycle";
            cout << endl;
        }
        else
        {
            cout << "graph does not contain cycle";
            cout << endl;
        }
    }

    return 0;
}