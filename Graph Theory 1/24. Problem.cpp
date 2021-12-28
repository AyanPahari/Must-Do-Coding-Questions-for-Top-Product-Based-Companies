#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> in;
vector<int> res;

//To find the topological sort of a graph(also takes care of cycles)
// link: https://www.spoj.com/problems/TOPOSORT/

bool kahn(int n)
{
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int curr = q.top();
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
    return res.size() == n;
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

    if (kahn(n) == true)
    {
        for (auto x : res)
        {
            cout << x << " ";
        }
    }
    else
    {
        cout << "Sandro fails.";
    }
    return 0;
}
