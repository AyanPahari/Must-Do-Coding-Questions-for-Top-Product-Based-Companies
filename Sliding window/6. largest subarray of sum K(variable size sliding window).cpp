int lenOfLongSubarr(int arr[], int N, int K)
{
    int i = 0;
    int j = 0;
    int maxi = 0;
    long long sum = 0;

    while (j < N)
    {
        sum += arr[j];

        if (sum < K)
        {
            j++;
        }
        else if (sum == K)
        {
            maxi = max(maxi, j - i + 1);
            j++;
        }
        else if (sum > K)
        {
            while (sum > K)
            {
                sum -= arr[i];
                i++;
            }
            if (sum == K)
            {
                maxi = max(maxi, j - i + 1);
            }
            j++;
        }
    }
    return maxi;
}

//this will not work if negative numbers are also present in the array.