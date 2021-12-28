#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
// Finding number of connected components in Graph.
void dfs(int i, vector<int> &vis)
{
    if (vis[i] != 0)
    {
        return;
    }
    vis[i] = 1;
    for (auto nb : adj[i])
    {
        dfs(nb, vis);
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
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i, vis);
            count++;
        }
    }
    cout << count << endl;
    return 0;
}