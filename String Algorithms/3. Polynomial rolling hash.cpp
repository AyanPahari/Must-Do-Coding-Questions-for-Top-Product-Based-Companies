#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

long long getHash(string s)
{
    long long ans = 0;
    long long p = 31;
    long long factor = 1;

    for (auto ch : s)
    {
        ans = ans + ((ch - 'a' + 1) * factor) % mod;
        factor = (factor * p) % mod;
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << getHash(s);

    return 0;
}
