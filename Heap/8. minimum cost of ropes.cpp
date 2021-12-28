long long minCost(long long arr[], long long n)
{
    priority_queue<long long, vector<long long>, greater<long long>> minh;
    for (int i = 0; i < n; i++)
    {
        minh.push(arr[i]);
    }
    // This is nothing but optimal merge pattern or huffman coding.
    long long sum = 0;
    while (minh.size() > 1)
    {
        long long x = minh.top();
        minh.pop();
        long long y = minh.top();
        minh.pop();
        long long z = x + y;
        sum += z;
        minh.push(z);
    }
    return sum;
}