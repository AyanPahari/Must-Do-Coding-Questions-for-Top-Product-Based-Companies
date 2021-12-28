#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int count[n + 1] = {0};
        for (int i = 0; i < n; i++)
        {
            count[arr[i]]++;
        }
        int miss, rep;
        for (int i = 1; i <= n; i++)
        {
            if (count[i] == 0)
            {
                miss = i;
            }
            if (count[i] == 2)
            {
                rep = i;
            }
        }
        cout << rep << " " << miss << "\n";
    }
    return 0;
}
// this method only works for one missing and one duplicate.
// O(n) time complexity
//O(n) space complexity