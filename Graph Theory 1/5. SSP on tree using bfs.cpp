#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int n;
// Single source shortest path on trees
vector<int> bfs(int source)
{
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(source);
    dist[source] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto nb : adj[u])
        {
            if (dist[nb] != -1)
                continue;
            dist[nb] = dist[u] + 1;
            q.push(nb);
        }
    }
    return dist;
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
    vector<int> dist;
    dist = bfs(1);

    for (int i = 1; i < dist.size(); i++)
    {
        cout << dist[i] << " ";
    }
    return 0;
}