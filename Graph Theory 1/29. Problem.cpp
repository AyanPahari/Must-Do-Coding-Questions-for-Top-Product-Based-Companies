#include <bits/stdc++.h>
using namespace std;

int n;
char arr[31][31];
int dist[31][31];
bool vis[31][31];

//distance of shortest path from source point to destination using BFS.
// link: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/jungle-run/

bool isValid(int x, int y)
{
    if (x < 1 or y < 1 or x > n or y > n)
    {
        return false;
    }
    if (vis[x][y] == true or arr[x][y] == 'T')
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
    vis[x][y] = 1;
    dist[x][y] = 0;
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

                q.push({newX, newY});
                vis[newX][newY] = 1;
                dist[newX][newY] = dist[curX][curY] + 1;
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    int startX, startY, endX, endY;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 'S')
            {
                startX = i;
                startY = j;
            }
            if (arr[i][j] == 'E')
            {
                endX = i;
                endY = j;
            }
        }
    }

    bfs(startX, startY);

    cout << dist[endX][endY];
    return 0;
}
