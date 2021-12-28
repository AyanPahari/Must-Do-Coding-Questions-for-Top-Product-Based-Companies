#include <bits/stdc++.h>
using namespace std;
// Binary Representation upto 14 bits.
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 13; i >= 0; i--)
        {
            cout << ((n >> i) & 1);
        }
        cout << "\n";
    }
    return 0;
}