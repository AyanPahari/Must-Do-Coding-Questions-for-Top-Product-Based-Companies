#include <bits/stdc++.h>
using namespace std;

int n, e;
vector<int> in;
vector<int> out;
int timer = 1;
void dfs(int v, vector<int> &vis, vector<vector<int>> &adj)
{
    in.resize(n + 1, 0);
    out.resize(n + 1, 0);
    vis[v] = 1;
    in[v] = timer++;

    for (auto nb : adj[v])
    {
        if (vis[nb] == 0)
            dfs(nb, vis, adj);
    }
    out[v] = timer++;
}

int main()
{
    cin >> n >> e;
    vector<vector<int>> adj(n + 1);
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n + 1, 0);
    dfs(1, vis, adj);

    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        if (in[u] < in[v] && out[u] > out[v] || in[v] < in[u] && out[v] > out[u])
        {
            cout << "one node lies in the subtree of other node" << endl;
        }
        else
        {
            cout << "one node does not lie in the subtree of other node" << endl;
        }
    }
    return 0;
}
