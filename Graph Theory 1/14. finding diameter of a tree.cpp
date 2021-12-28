#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

void dfs(int v, vector<int> &vis, vector<int> &dist, int d)
{
    vis[v] = 1;
    dist[v] = d;

    for (auto nb : adj[v])
    {
        if (vis[nb] == 0)
            dfs(nb, vis, dist, dist[v] + 1);
    }
}

int main()
{
    int n;
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
    vector<int> vis(n + 1, 0);
    vector<int> dist(n + 1, 0);
    dfs(1, vis, dist, 0);
    int index = 0;
    int maxi = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] > maxi)
        {
            maxi = dist[i];
            index = i;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
        dist[i] = 0;
    }

    dfs(index, vis, dist, 0);
    for (int i = 1; i <= n; i++)
    {
        maxi = max(maxi, dist[i]);
    }

    cout << maxi;

    return 0;
}