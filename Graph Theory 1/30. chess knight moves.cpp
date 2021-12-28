#include <bits/stdc++.h>
using namespace std;

int dist[10][10];
bool vis[10][10];
int startX, startY, endX, endY;

// minimum knight moves required to reach from source to destination in a chess board.
// link: https://www.codechef.com/problems/PRGCUP01

bool isValid(int x, int y)
{
    if (x < 1 or y < 1 or x > 8 or y > 8)
    {
        return false;
    }
    if (vis[x][y] == true)
    {
        return false;
    }
    return true;
}

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int bfs(int x, int y)
{
    queue<pair<int, int>> q;
    vis[x][y] = 1;
    dist[x][y] = 0;
    q.push({x, y});

    if (x == endX and y == endY)
    {
        return dist[x][y];
    }

    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            if (isValid(curX + dx[i], curY + dy[i]))
            {
                int newX = curX + dx[i];
                int newY = curY + dy[i];

                q.push({newX, newY});
                vis[newX][newY] = 1;
                dist[newX][newY] = dist[curX][curY] + 1;

                if (newX == endX and newY == endY)
                {
                    return dist[newX][newY];
                }
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
    int T;
    cin >> T;
    while (T--)
    {

        for (int i = 1; i <= 8; i++)
        {
            for (int j = 1; j <= 8; j++)
            {
                vis[i][j] = 0;
                dist[i][j] = 0;
            }
        }
        string start, end;
        cin >> start >> end;

        startX = start[0] - 'a' + 1;
        startY = start[1] - '0';
        endX = end[0] - 'a' + 1;
        endY = end[1] - '0';

        cout << bfs(startX, startY) << endl;
    }
    return 0;
}
