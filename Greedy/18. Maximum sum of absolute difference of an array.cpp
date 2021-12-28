// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        cout << maxSum(arr, n) << endl;
    }
    return 0;
} // } Driver Code Ends

long long int maxSum(int arr[], int n)
{
    sort(arr, arr + n);
    int sum = 0, i = 0, j = n - 1;
    int count = 0;
    while (i < j) //applying the two pointer approach after seeing the pattern
    {
        count++;
        sum += abs(arr[i] - arr[j]);
        if (count % 2 == 0)
            j--;
        else
            i++;
    }
    int mid = n / 2;
    sum += abs(arr[0] - arr[mid]);

    return sum;

    /* count is being used to maintain the point we are at the current time in array.
you will only get max absolute difference if smallest element is followed by biggest element which is followed 
by 2nd smallest number and it is followed by 2nd biggest number and so on. (numbers are in increasing order at 
even index and decresing order at odd index).
if we are at index 0(even index) we will be considering the smallest number so i is increased. 
and so is the count is also increased, now we are at index 1(count==1) so by logic largest number should be taken into account. 
so jth element which is pointing to the largest element is taken and as we have used this number j is moved to second highest element.*/
}