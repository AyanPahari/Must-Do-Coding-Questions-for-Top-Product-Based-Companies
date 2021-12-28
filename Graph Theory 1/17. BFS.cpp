#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> dist;
vector<int> vis;

// finding single source shortest path using bfs.

vector<int> bfs(int source)
{
    queue<int> q;
    vis[source] = 1;
    dist[source] = 0;
    q.push(source);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto nb : adj[u])
        {
            if (vis[nb] == 0)
            {
                vis[nb] = 1;
                dist[nb] = dist[u] + 1;
                q.push(nb);
            }
        }
    }
    return dist;
}

int main()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dist.resize(n + 1, 0);
    vis.resize(n + 1, 0);
    dist = bfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    return 0;
}