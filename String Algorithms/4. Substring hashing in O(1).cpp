#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long dp[1000001];
long long inv[1000001];

long long power(long long a, long long n)
{
    long long result = 1;

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
    long long p = 31;
    long long p_power = 1;
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

long long substringHash(int L, int R)
{
    long long result = dp[R];

    if (L > 0)
        result = (result - dp[L - 1] + mod) % mod;

    result = (result * inv[L]) % mod;

    return result;
}

int main()
{
    string input_string;
    int L, R;

    cin >> input_string;
    init(input_string);

    cin >> L >> R;
    cout << substringHash(L, R);
}
