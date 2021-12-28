#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define care                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL), cout.tie(NULL);

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    care int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        ll arr[100] = {0};
        arr[1] = 2;
        arr[2] = 3;
        for (int i = 3; i <= n; i++)
        {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        ll temp = pow(2, n) - arr[n];
        cout << temp << "\n";
    }
    return 0;
}
