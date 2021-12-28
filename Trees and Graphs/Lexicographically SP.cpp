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

// Given an undirected, unweighted graph and a src and destination,
// Find the Lexicographically smallest path between src and destination.

void modified_dfs(int i, vector<int> &vis, vector<int> &current_path)
{
    vis[i] = 1;
    current_path.push_back(i);
    if (i == dest)
    {
        for (auto it : current_path)
        {
            cout << it << " ";
        }
        exit(0);
    }
    for (auto nb : adj[i])
    {
        if (vis[nb] == 0)
        {
            modified_dfs(nb, vis, current_path);
        }
    }
    current_path.pop_back();
}

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
    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }
    vector<int> current_path;
    vector<int> vis(n + 1, 0);
    modified_dfs(src, vis, current_path);
    cout << "Path does not exist";
    return 0;
}