#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using boost::multiprecision::cpp_int;

using namespace std;
#define ll long long int
#define ul unsigned long int
#define mod 1000000007
#define care                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL), cout.tie(NULL);

int n, m, src, dest;
vector<vector<int>> adj;
vector<int> dist;

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
        for (auto n : adj[u])
        {
            if (dist[n] != -1)
            {
                continue;
            }
            dist[n] = dist[u] + 1;
            q.push(n);
        }
    }
    return dist;
}

vector<int> get_path()
{
    vector<int> ans;
    vector<int> d1 = bfs(src);
    vector<int> d2 = bfs(dest);

    for (int i = 1; i <= n; i++)
    {
        if (d1[i] != -1 and d2[i] != -1 and d1[dest] == d1[i] + d2[i])
        {
            ans.push_back(i);
        }
    }
    return ans;
}

// Given an undirected, unweighted graph and a src and destination,
// Find all the nodes which are part of atleast one shortest path between src and destination.

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m >> src >> dest;
    adj.resize(n + 1);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans = get_path();
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}