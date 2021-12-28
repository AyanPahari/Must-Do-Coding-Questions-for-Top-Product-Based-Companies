#include <bits/stdc++.h>
using namespace std;

bool is_Prime[10002];
void sieve()
{
    int maxN = 10002;
    for (int i = 1; i <= maxN; i++)
    {
        is_Prime[i] = true;
    }
    is_Prime[0] = is_Prime[1] = false;
    //Processing time:O(Nlog(logN))
    //Answer Query: O(1)
    //Extra Space: O(N)
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
}

int main()
{
    int L, R;
    cin >> L >> R;
    sieve();

    for (int i = L; i <= R; i++)
    {
        if (is_Prime[i])
        {
            cout << i << " ";
        }
    }
    return 0;
}

//Link: https://www.hackerearth.com/practice/math/number-theory/primality-tests/practice-problems/algorithm/prime-interval/