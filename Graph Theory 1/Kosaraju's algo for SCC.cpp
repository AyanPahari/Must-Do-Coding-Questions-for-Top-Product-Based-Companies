#include <bits/stdc++.h>
using namespace std;

vector<int> ar[1001];
vector<int> tr[1001];
int vis[1001];
vector<int> order, SCC;

// This algorithm is used to find the number of strongly connected components in a directed graph.

// Important points in kosaraju's algorithm:

// 1. graph and transposed graph have the same strongly connected components.
// 2. condensation graph.
// 3. acyclic property of acyclic graph.
// 4. out[c_i]>out[c_j] if there is an edge from c_i to c_j in condensation graph.

void dfs(int node)
{
    vis[node] = 1;

    for (auto nb : ar[node])
    {
        if (vis[nb] == 0)
        {
            dfs(nb);
        }
    }
    order.push_back(node);
}

void dfs1(int node)
{
    vis[node] = 1;

    for (auto nb : tr[node])
    {
        if (vis[nb] == 0)
        {
            dfs1(nb);
        }
    }
    SCC.push_back(node);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
        {
            ar[i].clear();
            tr[i].clear();
            vis[i] = 0;
        }
        order.clear();
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            ar[u].push_back(v);
            tr[v].push_back(u);
        }

        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                dfs(i);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            vis[i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            if (vis[order[n - i]] == 0)
            {
                SCC.clear();
                dfs1(order[n - i]);

                cout << "dfs1() called from " << order[n - i] << " and printing SCC" << endl;
                for (int node : SCC)
                    cout << node << " ";
                cout << endl;
            }
        }
    }
    return 0;
}

// Input:
// 1
// 7 8
// 1 2
// 2 3
// 3 1
// 4 3
// 7 4
// 7 5
// 5 6
// 6 7
