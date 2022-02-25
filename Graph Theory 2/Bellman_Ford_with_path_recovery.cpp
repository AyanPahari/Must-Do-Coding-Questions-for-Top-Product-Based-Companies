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
    int a, b, w;
};

void bellman_ford(vector<edge> &edges, int src, int dst, int n)
{
    vector<int> dist(n + 1, inf);
    vector<int> par(n + 1, -1);
    int m = edges.size();
    dist[src] = 0;
    while (1)
    {
        bool flag = false;
        for (int i = 0; i < m; i++)
        {
            if (dist[edges[i].a] < inf && dist[edges[i].b] > dist[edges[i].a] + edges[i].w)
            {
                dist[edges[i].b] = dist[edges[i].a] + edges[i].w;
                par[edges[i].b] = edges[i].a;
                flag = true;
            }
        }
        if (flag == false)
            break;
    }

    if (dist[dst] == inf)
    {
        cout << "No path exists from " << src << " to " << dst << endl;
    }
    else
    {
        vector<int> path;
        for (int curr = dst; curr != -1; curr = par[curr])
        {
            path.push_back(curr);
        }
        reverse(path.begin(), path.end());
        cout << "Shortest Path from " << src << " to " << dst << endl;
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
    }

    cout << "Distance Array:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<edge> edges(m + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].a >> edges[i].b >> edges[i].w; // directed from a-->b
    }
    int src = 1;
    int dst = 5;
    bellman_ford(edges, src, dst, n);
    return 0;
}