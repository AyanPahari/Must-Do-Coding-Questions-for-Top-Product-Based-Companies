#include <bits/stdc++.h>
using namespace std;

bool is_Prime[87000009];
vector<int> prime;

void sieve()
{
    int maxN = 87000009;
    for (int i = 1; i <= maxN; i++)
    {
        is_Prime[i] = true;
    }
    is_Prime[0] = is_Prime[1] = false;

    for (int i = 3; i <= maxN; i++)
    {
        if (i % 2 == 0)
        {
            is_Prime[i] = false;
        }
    }

    for (int i = 3; i * i <= maxN; i++)
    {
        if (is_Prime[i])
        {
            for (int j = i * i; j <= maxN; j += 2 * i)
            {
                is_Prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= maxN; i++)
    {
        if (is_Prime[i] == true)
        {
            prime.push_back(i);
        }
    }
}

int main()
{
    sieve();
    int T;
    cin >> T;
    while (T--)
    {
        int q;
        cin >> q;
        cout << prime[q - 1] << endl;
    }
    return 0;
}

//finding the Kth prime
// link: https://www.spoj.com/problems/TDKPRIME/