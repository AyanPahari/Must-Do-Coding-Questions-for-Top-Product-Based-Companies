class Solution
{
public:
    static bool comp(vector<int> a, vector<int> b)
    {
        return a[1] > b[1];
    }

    //similar to fractional knapsack
    //time:O(nlogn)
    //space:O(1)
    int maximumUnits(vector<vector<int>> &arr, int W)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end(), comp);
        int profit = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i][0] <= W)
            {
                profit += arr[i][0] * arr[i][1];
                W -= arr[i][0];
            }
            else
            {
                profit += W * arr[i][1];
                break;
            }
        }
        return profit;
    }
};