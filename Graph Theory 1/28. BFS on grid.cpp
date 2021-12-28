#include <bits/stdc++.h>
using namespace std;

int n, m;
bool vis[1001][1001];
int dist[1001][1001];

bool isValid(int x, int y)
{
    if (x < 1 or x > n or y > m or y < 1)
    {
        return false;
    }
    if (vis[x][y] == true)
    {
        return false;
    }
    return true;
}

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    dist[x][y] = 0;
    vis[x][y] = 1;
    q.push({x, y});

    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            if (isValid(curX + dx[i], curY + dy[i]))
            {
                int newX = curX + dx[i];
                int newY = curY + dy[i];

                dist[newX][newY] = dist[curX][curY] + 1;
                vis[newX][newY] = 1;
                q.push({newX, newY});
            }
        }
    }
    cout << "Distance Array" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m;
    bfs(1, 1);
    return 0;
}