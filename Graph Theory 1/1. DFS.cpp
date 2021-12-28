#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
// to find the dfs of an undirected graph.
void dfs(int i, vector<int> &vis)
{
    vis[i] = 1;
    cout << i << "->";
    for (auto nb : adj[i])
    {
        if (vis[nb] == 0)
        {
            dfs(nb, vis);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    adj.resize(n + 1);
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n + 1, 0);
    dfs(1, vis);
    return 0;
}