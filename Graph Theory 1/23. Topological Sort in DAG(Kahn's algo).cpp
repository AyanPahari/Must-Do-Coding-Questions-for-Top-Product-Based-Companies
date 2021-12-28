#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> in;

//This algorithm will work provided that the graph doesn't contain any cycles.

void kahn(int n)
{
    queue<int> q;
    vector<int> res;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int curr = q.front();
        res.push_back(curr);
        q.pop();

        for (auto child : adj[curr])
        {
            in[child]--;
            if (in[child] == 0)
            {
                q.push(child);
            }
        }
    }
    cout << "Topological Sort: ";
    for (auto x : res)
    {
        cout << x << " ";
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    in.resize(n + 1, 0);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in[v]++;
    }

    kahn(n);
    return 0;
}
