#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int n;
vector<int> dist;
vector<int> vis;
// Single source shortest path on trees
void dfs(int node, int d)
{
    vis.resize(n + 1, 0);
    dist.resize(n + 1, 0);
    vis[node] = 1;
    dist[node] = d;

    for (auto nb : adj[node])
    {
        if (vis[nb] == 0)
        {
            dfs(nb, dist[node] + 1);
        }
    }
}

int main()
{
    cin >> n;
    adj.resize(n + 1);
    int e = n - 1;
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);

    for (int i = 1; i < dist.size(); i++)
    {
        cout << dist[i] << " ";
    }
    return 0;
}