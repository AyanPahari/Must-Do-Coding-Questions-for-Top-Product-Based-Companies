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

int n;
vector<vector<int>> adj;

void dfs(int curr = 1,int par=-1){
 
    cout << curr << endl;
    for(auto neigh:adj[curr]){
        if(neigh==par)
            continue;
        dfs(neigh, curr);
    }
}

    int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin>>n;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    return 0;
}