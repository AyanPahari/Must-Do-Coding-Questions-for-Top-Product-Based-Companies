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

void union_dsu(int a, int b)
{
    par[a] = par[a] + par[b];
    par[b] = a;
}

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    for (int i = 1; i <= n; i++)
    {
        par[i] = -1;
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
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (par[i] < 0)
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}

//Problem link: https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/