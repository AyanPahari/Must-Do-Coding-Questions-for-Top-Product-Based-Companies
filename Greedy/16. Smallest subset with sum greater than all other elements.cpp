#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<int>()); //sorting in dec order to get the greatest element in front
    int len = 0, sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    int sum_till = 0; //sum of the subset
    //the idea is we start picking the large elements for the subset to reduce the subset size
    for (int i = 0; i < n; i++)
    {
        sum_till += arr[i];
        len++;
        if (sum_till > (sum - sum_till)) //if subset sum greater than the sum of rest of the elements, just come out of the loop.
            break;
    }
    cout << len;
    return 0;
}
