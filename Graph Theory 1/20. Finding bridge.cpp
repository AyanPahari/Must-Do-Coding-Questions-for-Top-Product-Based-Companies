#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> vis, in, low;
int timer;

void dfs(int node, int par)
{
    vis[node] = 1;
    in[node] = low[node] = timer;
    timer++;

    for (auto child : adj[node])
    {
        if (child == par)
        {
            continue;
        }
        else if (vis[child] == 1)
        {
            //child--node is a back edge
            low[node] = min(low[node], in[child]);
        }
        else
        {
            //child--node is a forward edge
            dfs(child, node);
            if (low[child] > in[node])
            {
                cout << node << " -- " << child << " is a bridge " << endl;
            }
            low[node] = min(low[node], low[child]);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
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
    vis.resize(n + 1, 0);
    in.resize(n + 1, 0);
    low.resize(n + 1, 0);

    dfs(1, -1);

    return 0;
}