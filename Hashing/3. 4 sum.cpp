class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int low = j + 1;
                int high = n - 1;
                int rem_sum = target - nums[i] - nums[j];

                while (low < high)
                {
                    int two_sum = nums[low] + nums[high];
                    if (rem_sum < two_sum)
                        high--;
                    else if (rem_sum > two_sum)
                        low++;
                    else
                    {
                        vector<int> output(4, 0);
                        output[0] = nums[i];
                        output[1] = nums[j];
                        output[2] = nums[low];
                        output[3] = nums[high];
                        res.push_back(output);

                        while (low < high && nums[low] == output[2])
                            low++;
                        while (low < high && nums[high] == output[3])
                            high--;
                    }
                }
                while (j + 1 < n && nums[j] == nums[j + 1])
                    j++;
            }
            while (i + 1 < n && nums[i + 1] == nums[i])
                ++i;
        }
        return res;
    }
};