class Solution
{
public:
    //Naive approach using sorting
    //time:O(nlogn)
    //space:O(1)
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int count = 1;
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            if (i + 1 < n && nums[i + 1] == nums[i] + 1)
            {
                count++;
                ans = max(ans, count);
            }
            else if (i + 1 < n && nums[i + 1] == nums[i])
            {
                continue;
            }
            else
                count = 1;
        }
        return ans;
    }
};

class Solution
{
public:

    //optimal approach using hashset
    //time:O(n)
    //space:O(n)
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 0)
            return 0;

        unordered_set<int> s;
        int longest = 0;

        for (auto it : nums)
            s.insert(it);

        for (auto it : nums)
        {
            if (!s.count(it - 1))
            {
                int curr_num = it;
                int curr_long = 1;

                while (s.count(curr_num + 1))
                {
                    curr_num++;
                    curr_long++;
                }
                longest = max(longest, curr_long);
            }
        }
        return longest;
    }
};