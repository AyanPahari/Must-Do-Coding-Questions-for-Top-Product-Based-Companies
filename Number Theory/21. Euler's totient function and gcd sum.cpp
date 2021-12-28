#include <iostream>
using namespace std;

int Phi[1000001];

void init()
{
    int maxN = 1000000;
    for (int i = 1; i <= maxN; i++)
    {
        Phi[i] = i;
    }
    for (int i = 2; i <= maxN; i++)
    {
        if (Phi[i] == i)
        {
            for (int j = i; j <= maxN; j += i) // this preprocessing step takes nlog(logn) time
            {
                Phi[j] /= i;
                Phi[j] *= (i - 1);
            }
        }
    }
}

int get_count(int d, int n)
{
    return Phi[n / d];
}

int main()
{
    // time complexity is NloglogN +q*sqrtN, where q is the number of query.
    int T, n;
    cin >> T;
    init();
    while (T--)
    {
        cin >> n;
        int res = 0;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                int d1 = i;     //first divisor
                int d2 = n / i; // second divisor , always occur in pairs
                res += d1 * get_count(d1, n);

                if (d1 != d2) // if not a perfect square
                {
                    res += d2 * get_count(d2, n);
                }
            }
        }
        cout << res << endl;
    }

    return 0;
}
