#include <bits/stdc++.h>
using namespace std;
#define P 1000000007
int F[1000001];

int power(int a, int n)
{
    int res = 1;
    while (n)
    {
        if (n % 2 == 0)
        {
            a = (a * 1LL * a) % P;
            n /= 2;
        }
        else
        {
            res = (res * 1LL * a) % P;
            n--;
        }
    }
    return res;
}

int C(int n, int k)
{

    if (k > n)
    {
        return 0;
    }
    int res = F[n];
    res = (res * 1LL * power(F[k], P - 2)) % P;  //calculating inv(F[k]) using modulo inverse method
    res = (res * 1LL * power(F[n - k], P - 2)) % P; //calculating inv(F[n-k]) using modulo inverse method

    return res;
}

int main()
{
    F[0] = F[1] = 1;
    for (int i = 2; i <= 1000000; i++)
    {
        F[i] = (F[i - 1] * 1LL * i) % P;
    }
    int n, k;
    cin >> n >> k;
    cout << C(n, k);
    return 0;
}

//Program to calculate binary coefficient using modulo inverse