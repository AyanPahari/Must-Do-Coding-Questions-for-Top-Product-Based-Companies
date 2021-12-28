#include <bits/stdc++.h>
using namespace std;
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
        if (n % 2 == 0)
        {
            cout << "even"
                 << "\n";
        }
        else
        {
            cout << "odd"
                 << "\n";
        }
    }
    return 0;
}