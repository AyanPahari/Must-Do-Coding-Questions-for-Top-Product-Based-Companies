vector<int> topKFrequent(vector<int> &arr, int k)
{
    unordered_map<int, int> mp;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    vector<int> res;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;

    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        minh.push({i->second, i->first});

        if (minh.size() > k)
        {
            minh.pop();
        }
    }

    while (!minh.empty())
    {
        int x = minh.top().second;
        res.push_back(x);
        minh.pop();
    }
    return res;
}