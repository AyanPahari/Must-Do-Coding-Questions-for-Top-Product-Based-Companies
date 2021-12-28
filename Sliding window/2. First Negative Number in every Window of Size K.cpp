vector<long long> printFirstNegativeInteger(long long int arr[],
                                            long long int N, long long int K)
{

    int i = 0;
    int j = 0;
    list<long long> lis;
    vector<long long> res;

    while (j < N)
    {
        if (arr[j] < 0)
        {
            lis.push_back(arr[j]);
        }
        if (j - i + 1 < K)
        {
            j++;
        }
        else if (j - i + 1 == K)
        {
            if (lis.size() == 0)
            {
                res.push_back(0);
            }
            else
            {
                res.push_back(lis.front());

                if (arr[i] == lis.front())
                {
                    lis.pop_front();
                }
            }
            i++;
            j++;
        }
    }
    return res;
}