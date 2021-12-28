#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
//check if tree or not.
// link: https://www.spoj.com/problems/PT07Y/
void dfs(int i, vector<int> &vis)
{
    if (vis[i] == 1)
        return;
    vis[i] = 1;
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
    int n, e;
    cin >> n >> e;
    adj.resize(n + 1);
    int x = e;
    while (x--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n + 1, 0);
    dfs(1, vis);

    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            flag = true;
            break;
        }
    }
    if (e == (n - 1) and flag == false)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}