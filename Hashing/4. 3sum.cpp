class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        if (nums.size() == 0)
            return res;

        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            int rem_sum = -nums[i];
            int low = i + 1;
            int high = n - 1;

            while (low < high)
            {
                int sum = nums[low] + nums[high];
                if (rem_sum > sum)
                    low++;
                else if (rem_sum < sum)
                    high--;
                else
                {
                    vector<int> output(3, 0);
                    output[0] = nums[i];
                    output[1] = nums[low];
                    output[2] = nums[high];
                    res.push_back(output);

                    while (low < high && nums[low] == output[1])
                        low++;
                    while (low < high && nums[high] == output[2])
                        high--;
                }
            }
            while (i + 1 < n && nums[i] == nums[i + 1])
                i++;
        }
        return res;
    }
};