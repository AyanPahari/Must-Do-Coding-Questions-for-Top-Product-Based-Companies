vector<int> max_of_subarrays(int *arr, int n, int k)
{
    vector<int> res;
    int i = 0;
    int j = 0;
    deque<int> q;

    while (j < n)
    {
        while (q.size() > 0 and q.back() < arr[j])
        {
            q.pop_back(); //this way we will always have the only the required elements in the queue i.e
                          // the maximum element at the front
        }
        q.push_back(arr[j]);

        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            res.push_back(q.front());
            if (arr[i] == q.front())
            {
                q.pop_front();
            }
            i++;
            j++;
        }
    }
    return res;
}