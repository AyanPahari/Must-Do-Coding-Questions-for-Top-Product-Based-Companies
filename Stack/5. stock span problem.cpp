vector<int> calculateSpan(int arr[], int n)
{
    stack<pair<int, int>> s;
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        if (s.size() == 0)
        {
            res.push_back(-1);
        }
        else if (s.size() > 0 and s.top().first > arr[i])
        {
            res.push_back(s.top().second);
        }
        else if (s.size() > 0 and s.top().first <= arr[i])
        {
            while (s.size() > 0 and s.top().first <= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                res.push_back(-1);
            }
            else if (s.top().first > arr[i])
            {
                res.push_back(s.top().second);
            }
        }
        s.push({arr[i], i});
    }
    for (int i = 0; i < n; i++)
    {
        res[i] = i - res[i];
    }
    return res;
}