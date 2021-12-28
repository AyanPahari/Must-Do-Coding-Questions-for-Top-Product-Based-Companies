#include <bits/stdc++.h>
using namespace std;

bool is_Prime[1000001];
void sieve()
{
    int maxN = 1000001;
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
    int maxN = 1000001;
    bool res[1000002];
    res[0] = res[1] = res[2] = false;
    sieve();
    int count = 1;
    for (int i = 3; i <= maxN; i++)
    {
        if (is_Prime[i] == true)
        {
            count++;
        }
        if (is_Prime[count] == true)
        {
            res[i] = true;
        }
    }
    int count1 = 0;
    int res1[1000002];
    for (int i = 0; i <= maxN; i++)
    {
        if (res[i] == true)
            count1++;
        res1[i] = count1;
    }
    int T;
    cin >> T;
    while (T--)
    {
        int L, R;
        cin >> L >> R;
        cout << res1[R] - res1[L - 1] << endl;
    }
    return 0;
}
