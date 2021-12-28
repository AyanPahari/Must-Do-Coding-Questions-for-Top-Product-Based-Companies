#include <bits/stdc++.h>
using namespace std;

int n, m;
bool vis[1001][1001];

bool isValid(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > m)
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

void dfs(int x, int y)
{
    vis[x][y] = true;

    cout << x << "," << y << endl;

    for (int i = 0; i < 4; i++)
    {
        if (isValid(x + dx[i], y + dy[i]))
        {
            dfs(x + dx[i], y + dy[i]);
        }
    }

    /*  if(isValid(x-1,y)){
        dfs(x-1,y);  //UP
    }
    if(isValid(x+1,y)){
        dfs(x+1,y);  //DOWN
    }
    if(isValid(x,y-1)){
        dfs(x,y-1);  //LEFT
    }
    if(isValid(x,y+1)){
        dfs(x,y+1);  //RIGHT
    }
    */
}

int main()
{
    cin >> n >> m;
    dfs(1, 1);

    return 0;
}
