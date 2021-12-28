// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to return list containing vertices in Topological order.
    int in[10001];

    vector<int> topSort(int n, vector<int> adj[])
    {
        queue<int> q;
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            if (in[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int u = q.front();
            res.push_back(u);
            q.pop();

            for (auto child : adj[u])
            {
                in[child]--;
                if (in[child] == 0)
                {
                    q.push(child);
                }
            }
        }
        return res;
    }

    vector<int> topoSort(int V, vector<int> adj[])
    {
        for (int i = 0; i < V; i++)
        {
            for (auto child : adj[i])
            {
                in[child]++;
            }
        }
        vector<int> res = topSort(V, adj);

        return res;
    }
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector<int> &res, vector<int> adj[])
{
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
} // } Driver Code Ends