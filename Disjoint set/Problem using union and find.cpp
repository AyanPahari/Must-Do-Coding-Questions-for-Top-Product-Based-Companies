#include <bits/stdc++.h>
using namespace std;

int par[100001];

int find(int node)
{
    if (node == par[node])
    {
        return node;
    }
    else
    {
        return find(par[node]);
    }
}

void union_dsu(int u, int v)
{
    int x = find(u);
    int y = find(v);

    if (x != y)
    {
        par[y] = x;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        union_dsu(u, v);
    }
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        mp[par[i]]++;
    }
    long long prod = 1;
    for (int i = 1; i <= n; i++)
    {
        if (mp[i] != 0)
        {
            prod *= mp[i];
        }
    }
    cout << prod << endl;
    return 0;
}

//size of a set and other applications
//Prob link: https://www.hackerearth.com/challenges/competitive/code-monk-disjoint-set-union-union-find/algorithm/teachers-dilemma-3/