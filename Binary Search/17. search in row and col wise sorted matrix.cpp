#include <iostream>
using namespace std;

int matSearch(int mat[][1001], int N, int M, int X)
{
    int largest = mat[N - 1][M - 1];
    int smallest = mat[0][0];

    if (X < smallest or X > largest)
        return 0;

    int i = 0;
    int j = M - 1;
    while (i < N and j >= 0)
    {
        if (mat[i][j] == X)
            return 1;
        else if (mat[i][j] > X)
            j--;
        else
            i++;
    }

    return 0;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int arr[1001][1001];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << matSearch(arr, n, m, k);
    return 0;
}
