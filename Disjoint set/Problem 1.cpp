#include <bits/stdc++.h>
using namespace std;

int par[100001];

int find(int a)
{
    vector<int> vec;
    while (par[a] > 0)
    {
        vec.push_back(a);
        a = par[a];
    }
    for (int i = 0; i < vec.size(); i++)
    {
        par[vec[i]] = a;
    }
    return a;
}

void union_dsu(int x, int y)
{
    par[x] = min(par[x], par[y]);
    par[y] = x;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        par[i] = -i;
    }
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        int x = find(u);
        int y = find(v);

        if (x != y)
        {
            union_dsu(x, y);
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        int par_u = find(u);
        int par_v = find(v);

        if (par_v == par_u)
        {
            cout << "TIE" << endl;
        }
        else
        {
            if (par[par_u] < par[par_v])
            {
                cout << u << endl;
            }
            else
            {
                cout << v << endl;
            }
        }
    }
    return 0;
}

//Problem link: https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/owl-fight/