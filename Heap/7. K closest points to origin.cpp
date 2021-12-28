class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        int rows = points.size();
        priority_queue<pair<int, vector<int>>> maxh;

        for (auto num : points)
        {
            int weight = num[0] * num[0] + num[1] * num[1]; //taking the sqrt here does not matter.
            maxh.push({weight, num});

            if (maxh.size() > k)
            {
                maxh.pop();
            }
        }

        vector<vector<int>> res;
        while (!maxh.empty())
        {
            res.push_back(maxh.top().second);
            maxh.pop();
        }

        return res;
    }
};