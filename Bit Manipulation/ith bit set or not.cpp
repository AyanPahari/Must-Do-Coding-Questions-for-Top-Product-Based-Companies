#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, i;
    cin >> n >> i;

    if ((n >> i) & 1)
    {
        cout << "Set";
    }
    else
    {
        cout << "Not Set";
    }
    return 0;
}
