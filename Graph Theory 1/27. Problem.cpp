#include <bits/stdc++.h>
using namespace std;

int n, m;
char arr[1001][1001];
bool vis[1001][1001];

//link : https://cses.fi/problemset/task/1192#:~:text=CSES%20%2D%20Counting%20Rooms&text=You%20are%20given%20a%20map,down%20through%20the%20floor%20squares.

bool isValid(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > m)
    {
        return false;
    }
    if (vis[x][y] == true || arr[x][y] == '#')
    {
        return false;
    }
    return true;
}

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y)
{
    vis[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        if (isValid(x + dx[i], y + dy[i]))
        {
            dfs(x + dx[i], y + dy[i]);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (vis[i][j] == false and arr[i][j] == '.')
            {
                count++;
                dfs(i, j);
            }
        }
    }
    cout << count;

    return 0;
}
