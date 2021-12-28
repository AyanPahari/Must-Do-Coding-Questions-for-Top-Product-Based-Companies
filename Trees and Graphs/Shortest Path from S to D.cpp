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

vector<int> bfs1(int source)
{
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(source);
    dist[source] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto n : adj[u])
        {
            if (dist[n] != -1)
            {
                continue;
            }
            dist[n] = dist[u] + 1;
            q.push(n);
        }
    }
    return dist;
}

vector<int> bfs2(int source)
{
    vector<int> dist(n + 1, -1);
    vector<int> par(n + 1, -1);
    queue<int> q;
    q.push(source);
    dist[source] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto n : adj[u])
        {
            if (dist[n] != -1)
            {
                continue;
            }
            dist[n] = dist[u] + 1;
            par[n] = u;
            q.push(n);
        }
    }
    return par;
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
    vector<int> dist = bfs1(1);
    vector<int> par = bfs2(1);
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == -1)
            cout << i << "\t"
                 << "No path exists";

        else
        {
            vector<int> cur_path;
            int curr = i;
            while (curr != -1)
            {
                cur_path.push_back(curr);
                curr = par[curr];
            }
            reverse(cur_path.begin(), cur_path.end());
            cout << i << "\t";
            for (auto it : cur_path)
                cout << it << " ";
            cout << endl;
        }
    }

    // cout << endl;
    // for (auto it : dist)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;
    // for (auto it : par)
    // {
    //     cout << it << " ";
    // }

    return 0;
}