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
vector<vector<int>> edges;
vector<int> par;
int n, m;

vector<int> restore_path(int s, int t, vector<int> const &par)
{
    vector<int> path;

    for (int v = t; v != s; v = par[v])
        path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());
    return path;
}

vector<vector<int>> floyd_warshall()
{
    vector<vector<int>> d(n + 1, vector<int>(n + 1, INF));
    par.resize(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        d[i][i] = 0;
    }
    for (auto e : edges)
    {
        d[e[0]][e[1]] = e[2];
    }
    for (int k = 1; k <= n; k++)
    {
        bool flag = false; // Optimization so that to break out if the distances stop updating after some rounds.
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (d[i][k] < INF and d[k][j] < INF)
                {
                    if (d[i][j] > d[i][k] + d[k][j])
                    {
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                        flag = true;
                        par[j] = i;
                    }
                }
            }
        }
        if (!flag)
        {
            break;
        }
    }
    // Check if a path from i to j have negative cycle: d[i][j]=-INF

    /*  for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int x=1;x<=n;x++){
                if(d[i][x]<INF and d[x][x]<0 and d[x][j]<INF){
                    d[i][j]=-INF;
                    break;
                }
            }
        }
    }
    */

    return d;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m;
    edges.resize(m);
    for (auto &e : edges)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e = {u, v, w};
    }
    vector<vector<int>> dist = floyd_warshall();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    vector<int> paths = restore_path(1, 3, par);
    for(auto it:paths){
        cout << it << ' ';
    }
    // cout << endl;
    // cout << "Shortest Path From Source to every other node reachable";
    // cout << endl;
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if (dist[i][j] != INF)
    //         {
    //             vector<int> path = restore_path(1, i, par);
    //             cout << i << "->"
    //                  << "\t";
    //             for (auto it : path)
    //             {
    //                 cout << it << " ";
    //             }
    //             cout<<endl;
    //         }
    //     }
    //     cout << endl;
    // }
    return 0;
}