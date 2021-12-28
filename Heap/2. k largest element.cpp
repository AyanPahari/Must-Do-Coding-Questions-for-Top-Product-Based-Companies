vector<int> kLargest(int arr[], int n, int k)
{
    vector<int> res;
    priority_queue<int, vector<int>, greater<int>> minh;

    for (int i = 0; i < n; i++)
    {
        minh.push(arr[i]);
        if (minh.size() > k)
            minh.pop();
    }
    while (!minh.empty())
    {
        int x = minh.top();
        minh.pop();
        res.push_back(x);
    }
    sort(res.begin(), res.end(), greater<int>());
    return res;
}