int maximumSumSubarray(int K, vector<int> &arr, int N)
{
    int i = 0;
    int j = 0;
    long long sum = 0;
    long long maxi = INT_MIN;
    while (j < N)
    {
        sum += arr[j];

        if (j - i + 1 < K)
        {
            j++;
        }
        else if (j - i + 1 == K)
        {
            maxi = max(maxi, sum);
            sum -= arr[i];
            i++;
            j++;
        }
    }
    return maxi;
}
// this is an example of fixed window sliding where the value of K is already given.