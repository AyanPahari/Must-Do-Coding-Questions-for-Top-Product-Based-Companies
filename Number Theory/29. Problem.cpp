#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int res = gcd(a, b);

        if (c % res == 0)
        {
            cout << "Case " << i << ": Yes" << endl;
        }
        else
        {
            cout << "Case " << i << ": No" << endl;
        }
    }

    return 0;
}
//given a,b,c tell whether solution exist or not for the equation ax+by=c
//using LDA to solve this equation
//link: https://www.spoj.com/problems/CEQU/