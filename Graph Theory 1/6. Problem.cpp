#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int n;
// Single source shortest path
// link: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/
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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

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
    int q;
    cin >> q;
    vector<int> Q(n + 1, 0);
    while (q--)
    {
        int x;
        cin >> x;
        Q[x] = 1;
    }
    vector<int> dist;
    dist = bfs(1);

    int mini = INT_MAX;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (Q[i] == 1)
        {
            if (dist[i] < mini)
            {
                mini = dist[i];
                ans = i;
            }
        }
    }

    cout << ans << endl;
    return 0;
}