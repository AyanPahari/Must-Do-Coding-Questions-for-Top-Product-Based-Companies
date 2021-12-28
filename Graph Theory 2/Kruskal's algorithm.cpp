#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int a;
    int b;
    int w;
};

int par[10001];
edge arr[100001];

bool comp(edge a, edge b)
{
    if (a.w < b.w)
    {
        return true;
    }
    return false;
}

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
    par[b] = a;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        par[i] = -1;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i].a >> arr[i].b >> arr[i].w;
    }
    sort(arr, arr + m, comp);

    long long sum = 0;

    for (int i = 0; i < m; i++)
    {
        int x = find(arr[i].a);
        int y = find(arr[i].b);

        if (x != y)
        {
            sum += arr[i].w;
            union_dsu(x, y);
        }
    }
    cout << sum << endl;
    return 0;
}