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
        ll  result = 0;
        ll arr[32];
        for (int i = 31; i >= 0;i--){
            int temp = (n >> i) & 1;
            arr[i]=temp;
        }
        for (int i = 0; i < 32; i++)
        {
            ll temp = pow(2, i);
            result += temp * arr[31 - i];
        }
        cout << result << "\n";
    }
    return 0;
}
