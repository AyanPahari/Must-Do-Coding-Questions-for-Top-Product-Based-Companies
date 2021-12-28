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
        ll arr[101];
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            result ^= arr[i];
        }
        cout << result << "\n";
    }
    return 0;
}
