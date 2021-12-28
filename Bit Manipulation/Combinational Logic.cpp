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
        bool A, B, C, D, E, F;
        cin >> A >> B >> C >> D >> E >> F;
        cout << (((~A) & B) | (C & D) | (E & (~F))) << "\n";
    }
    return 0;
}