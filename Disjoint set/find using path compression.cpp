#include <bits/stdc++.h>
using namespace std;

int parent[100001];

int find(int a)
{
    vector<int> vec;
    while (parent[a] > 0)
    {
        vec.push_back(a);
        a = parent[a];
    }
    for (int i = 0; i < vec.size(); i++)
    {
        parent[vec[i]] = a;
    }
    return a;
}

void Union(int a, int b)
{
    parent[a] += parent[b]; //adding size of set b to set a
    parent[b] = a;          //making a , parent of new set
}

int main()
{
    int n, m, a, b;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        parent[i] = -1; //initializing

    while (m--)
    {
        cin >> a >> b;
        a = find(a), b = find(b);

        if (a != b)
            Union(a, b);
    }

    long long int res = 1;

    for (int i = 1; i <= n; i++)
        if (parent[i] < 0)
            res = (res * abs(parent[i])) % 1000000007;

    cout << res;
}
