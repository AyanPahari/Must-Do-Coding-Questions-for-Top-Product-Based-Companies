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

int n, m;
vector<vector<int>> adj;

void dfs_cycle(int i, vector<int> &vis, int par, bool &cycle)
{
    vis[i] = 1;
    for (auto n : adj[i])
    {

        if (n == par)
        {
            continue;
        }

        if (vis[n] == 0)
        {
            dfs_cycle(n, vis, i, cycle);
        }
        else
        {
            cycle = true;
        }
    }
}

bool cycle_found()
{
    vector<int> vis(n + 1, 0);
    bool cycle = false;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            dfs_cycle(i, vis, -1, cycle);
        }
    }
    return cycle;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m;
    adj.resize(n + 1);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool find = cycle_found();
    if (find)
    {
        cout << "Cycle Found";
    }
    else
    {
        cout << "No Cycle Found";
    }
    return 0;
}