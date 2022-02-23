#include <bits/stdc++.h>
using namespace std;

#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define inf 1e16
#define int long long
#define float double

struct edge
{
    int u, v, wt;
};

int32_t main()
{
    int n, e;
    cin >> n >> e;
    vector<edge> edges(e + 1);
    for (int i = 0; i < e; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].wt;
    }
    vector<int> dist(n + 1, inf);
    dist[1] = 0;

    for (int i = 0; i < n; i++) // n-1 phases
    {
        for (int j = 0; j < e; j++) // traversing the entire edge list
        {
            if (dist[edges[j].u] < inf && dist[edges[j].v] > dist[edges[j].u] + edges[j].wt)
            {
                if (i == n - 1) // if values are still changing in the n-1 phase, that indicates the presence of negative weight cycle
                {
                    cout << "Negative cycle found" << endl;
                    break;
                }
                dist[edges[j].v] = dist[edges[j].u] + edges[j].wt;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dist[i] << " ";
    return 0;
}
