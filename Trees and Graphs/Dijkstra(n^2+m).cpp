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
vector<vector<pair<int, int>>> adj;
int n, m;

vector<int> restore_path(int s, int t, vector<int> const &p)
{
    vector<int> path;

    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());
    return path;
}

vector<int> dijkstra(int s, vector<int> &d, vector<int> &p)
{
    d.resize(n + 1, INF);
    p.resize(n + 1, -1);
    vector<bool> u(n + 1, false);

    d[s] = 0;
    for (int i = 1; i <= n; i++)
    {
        int v = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == INF)
            break;

        u[v] = true;
        for (auto edge : adj[v])
        {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to])
            {
                d[to] = d[v] + len;
                p[to] = v;
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
    adj.resize(n + 1);
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> p, d;
    vector<int> dist = dijkstra(1, d, p);

    cout << "Shortest Distance From Source:" << endl;
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << "\t" << dist[i] << endl;
    }
    cout << endl;
    cout << "Shortest Path From Source to every other node reachable";
    cout << endl;
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] != INF)
        {
            vector<int> path = restore_path(1, i, p);
            cout << i << "->"
                 << "\t";
            for (auto it : path)
            {
                cout << it << " ";
            }
        }
        cout << endl;
    }
    return 0;
}