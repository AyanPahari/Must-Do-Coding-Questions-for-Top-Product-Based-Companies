class Solution
{
public:
    static bool comp(vector<int> a, vector<int> b)
    {
        if (a[1] == b[1])
            return a[0] < b[0];
        return a[1] < b[1];
    }

    //Activity selection problem
    //time:O(nlogn)
    //space:O(n)

    int findMinArrowShots(vector<vector<int>> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end(), comp);
        int i = 0, j = 1;
        int count = 1;
        while (j < n)
        {
            if (arr[i][1] < arr[j][0])
            {
                count++;
                i = j;
                j++;
            }
            else
                j++;
        }
        return count;
    }
};