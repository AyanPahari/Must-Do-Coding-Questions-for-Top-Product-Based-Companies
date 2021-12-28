

//Novice Approach that takes O(M^3*N) time where M is the dimension of the square matrix and N is the power.

// #include <iostream>
// using namespace std;

// #define N 101
// int arr[N][N];
// int I[N][N];

// void matrix_mult(int I[][N], int arr[][N], int dim)
// {
//     int res[dim + 1][dim + 1];

//     for (int i = 1; i <= dim; i++)
//     {
//         for (int j = 1; j <= dim; j++)
//         {
//             res[i][j] = 0;
//             for (int k = 1; k <= dim; k++)
//             {
//                 res[i][j] += I[i][k] * arr[k][j];
//             }
//         }
//     }
//     for (int i = 1; i <= dim; i++)
//     {
//         for (int j = 1; j <= dim; j++)
//         {
//             I[i][j] = res[i][j];
//         }
//     }
// }

// void power(int arr[][N], int dim, int n)
// {

//     for (int i = 1; i <= dim; i++)
//     {
//         for (int j = 1; j <= dim; j++)
//         {
//             if (i == j)
//             {
//                 I[i][j] = 1;
//             }
//             else
//             {
//                 I[i][j] = 0;
//             }
//         }
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         matrix_mult(I, arr, dim);
//     }

//     for (int i = 1; i <= dim; i++)
//     {
//         for (int j = 1; j <= dim; j++)
//         {
//             arr[i][j] = I[i][j];
//         }
//     }
// }

// void print(int arr[][N], int dim)
// {
//     for (int i = 1; i <= dim; i++)
//     {
//         for (int j = 1; j <= dim; j++)
//         {
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

// int main()
// {
//     int T, n, dim;
//     cin >> T;
//     while (T--)
//     {
//         cin >> dim >> n;
//         for (int i = 1; i <= dim; i++)
//         {
//             for (int j = 1; j <= dim; j++)
//             {
//                 cin >> arr[i][j];
//             }
//         }
//         power(arr, dim, n);
//         print(arr, dim);
//     }
//     return 0;
// }

//Optimised Approach that takes O(M^3*logN) time where M is the dimension of the square matrix and N is the power.

#include <iostream>
using namespace std;

#define N 101
int arr[N][N];
int I[N][N];
typedef long long in;

void matrix_mult(int I[][N], int arr[][N], int dim)
{
    int res[dim + 1][dim + 1];

    for (int i = 1; i <= dim; i++)
    {
        for (int j = 1; j <= dim; j++)
        {
            res[i][j] = 0;
            for (int k = 1; k <= dim; k++)
            {
                res[i][j] += I[i][k] * arr[k][j];
            }
        }
    }
    for (int i = 1; i <= dim; i++)
    {
        for (int j = 1; j <= dim; j++)
        {
            I[i][j] = res[i][j];
        }
    }
}

void power(int arr[][N], int dim, int n)
{

    for (int i = 1; i <= dim; i++)
    {
        for (int j = 1; j <= dim; j++)
        {
            if (i == j)
            {
                I[i][j] = 1;
            }
            else
            {
                I[i][j] = 0;
            }
        }
    }

    while (n)
    {
        if (n % 2 == 0)
        {
            matrix_mult(arr, arr, dim);
            n /= 2;
        }
        else
        {
            matrix_mult(I, arr, dim);
            n--;
        }
    }

    for (int i = 1; i <= dim; i++)
    {
        for (int j = 1; j <= dim; j++)
        {
            arr[i][j] = I[i][j];
        }
    }
}

void print(int arr[][N], int dim)
{
    for (int i = 1; i <= dim; i++)
    {
        for (int j = 1; j <= dim; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int T, n, dim;
    cin >> T;
    while (T--)
    {
        cin >> dim >> n;
        for (int i = 1; i <= dim; i++)
        {
            for (int j = 1; j <= dim; j++)
            {
                cin >> arr[i][j];
            }
        }
        power(arr, dim, n);
        print(arr, dim);
    }
    return 0;
}
