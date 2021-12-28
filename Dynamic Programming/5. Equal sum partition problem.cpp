int equalPartition(int N, int arr[])
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
    }
    if (sum % 2 != 0)
    {
        return 0; //if sum is odd then we cannot divide it into two subsets of equal sum
    }
    else
    {
        int new_sum = sum / 2;

        bool t[N + 1][new_sum + 1]; //if the sum is even, then the problem is
                                    //simply reduced to finding if their exist a subset sum of value
                                    //equal to sum/2

        for (int i = 0; i < N + 1; i++)
        {
            for (int j = 0; j < new_sum + 1; j++)
            {
                if (i == 0)
                {
                    t[i][j] = false;
                }
                if (j == 0)
                {
                    t[i][j] = true;
                }
            }
        }
        for (int i = 1; i < N + 1; i++)
        {
            for (int j = 1; j < new_sum + 1; j++)
            {
                if (arr[i - 1] <= j)
                {
                    t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
                }
                else
                {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        return t[N][new_sum];
    }
}