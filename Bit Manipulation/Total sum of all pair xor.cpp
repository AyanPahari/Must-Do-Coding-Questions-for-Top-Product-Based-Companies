#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[1001];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int res = 0;
    for (int i = 0; i < 32; i++)
    {
        int one = 0, zero = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] & (1 << i))
            {
                one++;
            }
            else
            {
                zero++;
            }
        }
        int p = one * zero;
        res += (1 << i) * p;
    }
    cout << res;
    return 0;
}
/*
Input : arr[] = {7, 3, 5}
Output : 12
7 ^ 3 = 4
3 ^ 5 = 6
7 ^ 5 = 2
Sum = 4 + 6 + 2 
    = 12

Input : arr[] = {5, 9, 7, 6}
Output : 47
5 ^ 9 = 12
9 ^ 7 = 14
7 ^ 6 = 1
5 ^ 7 = 2
5 ^ 6 = 3
9 ^ 6 = 15
Sum = 12 + 14 + 1 + 2 + 3 + 15
    = 47
*/