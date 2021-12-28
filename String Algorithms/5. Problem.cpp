#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long lli;
lli dp[1000001];
lli inv[1000001];

lli power(long long a, long long n)
{
    lli result = 1;

    while (n)
    {
        if (n % 2 != 0)
        {
            result = (result * a) % mod;
            n--;
        }
        else
        {
            a = (a * a) % mod;
            n /= 2;
        }
    }
    return result;
}

void init(string input_string)
{
    lli p = 31;
    lli p_power = 1;
    inv[0] = 1;
    dp[0] = (input_string[0] - 'a' + 1);

    for (int i = 1; i < input_string.size(); i++)
    {
        char ch = input_string[i];

        p_power = (p_power * p) % mod;
        inv[i] = power(p_power, mod - 2);

        dp[i] = (dp[i - 1] + (ch - 'a' + 1) * p_power) % mod;
    }
}

lli getHash(string key)
{
    lli value = 0;
    lli p = 31;
    lli p_power = 1;

    for (char ch : key)
    {
        value = (value + (ch - 'a' + 1) * p_power) % mod;
        p_power = (p_power * p) % mod;
    }

    return value;
}

lli substringHash(int L, int R)
{
    int result = dp[R];

    if (L > 0)
        result = (result - dp[L - 1] + mod) % mod;

    result = (result * inv[L]) % mod;

    return result;
}

int main()
{
    string haystack, needle;
    int n, L, R, answer;
    bool flag = false;

    while (cin >> n)
    {
        cin >> needle;
        cin >> haystack;

        lli needleHash = getHash(needle);

        init(haystack);

        for (L = 0, R = needle.size() - 1; R < haystack.size(); L++, R++)
        {
            if (needleHash == substringHash(L, R))
                cout << L << endl;
        }

        cout << endl;
    }
}
//pattern matching using the rolling polynomial hash function
//link: https://www.spoj.com/problems/NHAY/