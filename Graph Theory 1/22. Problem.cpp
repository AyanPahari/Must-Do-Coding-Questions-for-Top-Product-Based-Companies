#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> low, in, vis;
int timer;
set<int> s;

// finding the number of articulation points in a graph
// link : https://www.spoj.com/problems/SUBMERGE/

void dfs(int node, int p = -1)
{
    vis[node] = true;
    in[node] = low[node] = timer;
    timer++;
    int children = 0;
    for (auto child : adj[node])
    {
        if (child == p)
            continue;
        if (vis[child])
        {
            low[node] = min(low[node], in[child]);
        }
        else
        {
            dfs(child, node);
            low[node] = min(low[node], low[child]);
            if (low[child] >= in[node] && p != -1)
                s.insert(node);
            ++children;
        }
    }
    if (p == -1 && children > 1)
        s.insert(node);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    while (1)
    {
        cin >> n >> m;
        if (n == 0 and m == 0)
        {
            break;
        }
        adj.resize(n + 1);
        vis.resize(n + 1, 0);
        in.resize(n + 1, 0);
        low.resize(n + 1, 0);

        s.clear();

        timer = 0;
        for (int i = 1; i <= n; i++)
        {
            vis[i] = 0;
            in[i] = 0;
            low[i] = 0;
            adj[i].clear();
        }
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                dfs(i);
            }
        }
        cout << s.size() << endl;
    }
    return 0;
}
