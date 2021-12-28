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

const int INF = 1e9;
vector<vector<int>> edges;
int n, m;

bool detect_negative_cycle_affecting_from_source(int source)
{
    vector<int> d(n + 1, INF);
    d[source] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (auto e : edges)
        {
            int u = e[0], v = e[1], w = e[2];
            if (i <= n - 1)
            {
                if (d[u] < INF)
                {
                    d[v] = min(d[v], d[u] + w);
                }
            }
            else
            {
                if (d[u] + w < d[v])
                {
                    return true;
                }
            }
        }
    }
    return false;
}

vector<int> bellman_ford(int source)
{
    vector<int> d(n + 1, INF);
    d[source] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto e : edges)
        {
            int u = e[0], v = e[1], w = e[2];
            if (d[u] < INF)
            {
                d[v] = min(d[v], d[u] + w);
            }
        }
    }
    return d;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m;
    edges.resize(n + 1);
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    vector<int> dist = bellman_ford(1);

    cout << "Shortest Distance From Source:" << endl;
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << "\t" << dist[i] << endl;
    }
    return 0;
}