#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[1001][1001];
bool vis[1001][1001];

bool isValid(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > m)
    {
        return false;
    }
    if (vis[x][y] == true || arr[x][y] == 0)
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
            if (vis[i][j] == false and arr[i][j] == 1)
            {
                count++;
                dfs(i, j);
            }
        }
    }
    cout << "Connected components : " << count;

    return 0;
}

// input: 6 6
// 0 0 1 0 1 1
// 0 1 1 0 0 1
// 0 1 0 0 0 0
// 1 0 1 1 0 0
// 0 0 0 1 0 0
// 0 1 1 0 1 1