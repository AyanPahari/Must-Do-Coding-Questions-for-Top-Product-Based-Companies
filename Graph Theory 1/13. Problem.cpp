#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

//connected component count and size.
// link: https://www.codechef.com/problems/FIRESC/

void dfs(int v, vector<int> &vis, vector<vector<int>> &adj, int &counter)
{
    vis[v] = 1;
    counter++;

    for (auto nb : adj[v])
    {
        if (vis[nb] == 0)
            dfs(nb, vis, adj, counter);
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, e;
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
        int counter = 0;
        int comp = 0;
        long long ans = 1;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                dfs(i, vis, adj, counter);
                ans = (ans * counter) % mod;
                counter = 0;
                comp++;
            }
        }
        cout << comp << " " << ans << endl;
    }

    return 0;
}
