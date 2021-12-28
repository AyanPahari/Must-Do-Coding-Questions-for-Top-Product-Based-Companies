long long sumBetweenTwoKth(long long arr[], long long n, long long k1, long long k2)
{
    if (k1 == k2)
    {
        return 0;
    }
    priority_queue<long long, vector<long long>, greater<long long>> minh;
    for (int i = 0; i < n; i++)
    {
        minh.push(arr[i]);
    }
    long long diff = k2 - k1 - 1;
    while (k1--)
    {
        minh.pop();
    }
    long long res = 0;
    while (diff--)
    {
        res += minh.top();
        minh.pop();
    }
    return res;
}

//elements are assumed to be distinct here.