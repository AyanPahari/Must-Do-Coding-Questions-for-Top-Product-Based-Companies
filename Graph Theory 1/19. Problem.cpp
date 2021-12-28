#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

// number of nodes that are k distance away from a particular node or social networking
// link: https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/social-networking-graph/

vector<int> bfs(int node, vector<int> &vis, vector<int> dist)
{
    vis[node] = 1;
    dist[node] = 0;
    queue<int> q;
    q.push(node);

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
    int n, e;
    cin >> n >> e;
    adj.resize(n+1);
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int m;
    cin >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        vector<int> dist(n + 1, 0);
        vector<int> vis(n + 1, 0);

        dist = bfs(x, vis, dist);

        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == y)
            {
                count++;
            }
        }
        cout << count << endl;

        for (int i = 1; i <= n; i++)
        {
            vis[i] = 0;
            dist[i] = 0;
        }
    }
    return 0;
}