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

int main()
{
    init();
    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        cout << Phi[n] << endl; //each queries work in O(1) time
    }

    return 0;
}
