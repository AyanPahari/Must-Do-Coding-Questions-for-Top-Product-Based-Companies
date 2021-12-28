#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> subtree_size;
vector<int> vis;
//given a tree, construct an array subsize[], where subsize[v] stores the size of subtree rooted at node v.
int dfs(int node)
{
    vis[node] = 1;
    int curr_size = 1;

    for (auto child : adj[node])
    {
        if (vis[child] == 0)
        {
            curr_size += dfs(child);
        }
    }
    subtree_size[node] = curr_size;
    return curr_size;
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
    vis.resize(n + 1, 0);
    subtree_size.resize(n + 1, 0);

    dfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout << subtree_size[i] << "\t";
    }
    return 0;
}