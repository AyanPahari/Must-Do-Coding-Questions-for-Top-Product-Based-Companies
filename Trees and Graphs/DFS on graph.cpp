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

/* int n,m;
vector<vector<int>> adj;

  void dfs_util(int i, vector<int> &vis)
{
    vis[i] = 1;
    cout << i << endl;
    for (auto n : adj[i])
    {
        if (vis[n] == 0)
        {
            dfs_util(n, vis);
        }
    }
}

void dfs()
{
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            dfs_util(i, vis);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n>>m;
    adj.resize(n + 1);
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    return 0;
}

*/

int n, m, src;
vector<vector<int>> adj;

void dfs(int i, vector<int> &vis)
{
    if (vis[i])
    {
        return;
    }
    vis[i] = 1;
    cout << i << " ";
    for (auto nb : adj[i])
    {
        dfs(nb, vis);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m >> src;
    adj.resize(n + 1);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n + 1, 0);
    dfs(src, vis);
    return 0;
}