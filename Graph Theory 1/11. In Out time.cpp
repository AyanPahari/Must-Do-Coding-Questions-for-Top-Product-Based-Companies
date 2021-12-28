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
    cout << "In time: " << endl;
    for (int i = 1; i < in.size(); i++)
    {
        cout << in[i] << " ";
    }
    cout << endl;
    cout << "Out time: " << endl;
    for (int i = 1; i < out.size(); i++)
    {
        cout << out[i] << " ";
    }

    return 0;
}
