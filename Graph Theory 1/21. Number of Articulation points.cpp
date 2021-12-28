#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> vis, in, low;
int timer;

//* end point of a bridge will be an articulation point if the node has degree atleast 2.
//* it is not necessary for an articulation point to be an end point of a bridge.
//* finding bridges algorithm can not be used to find the articulation point.

set<int> s;

void dfs(int node, int p = -1)
{
    vis[node] = true;
    in[node] = low[node] = timer;
    timer++;
    int children = 0;
    for (auto child : adj[node])
    {
        if (child == p)
            continue;
        if (vis[child]==1)
        { // node--child is a back edge
            low[node] = min(low[node], in[child]);
        }
        else
        { // node--child is a forward edge
            dfs(child, node);
            low[node] = min(low[node], low[child]);
            if (low[child] >= in[node] && p != -1)
                s.insert(node); //stack is used to avoid the dublicates, because same point can be used as articulation points by many subtrees.
            ++children; //to count the number of subtree of root
        }
    }
    if (p == -1 && children > 1)
        s.insert(node);
}

int main()
{
    int n, e;
    cin >> n >> e;
    adj.resize(n + 1);
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vis.resize(n + 1, 0);
    in.resize(n + 1, 0);
    low.resize(n + 1, 0);

    dfs(1);

    cout << s.size() << endl;

    return 0;
}