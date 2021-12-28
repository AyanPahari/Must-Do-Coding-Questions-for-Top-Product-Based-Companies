class Solution
{
public:

    //better approach
    //time:O(nlogn)
    //space:O(n)
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]].push_back(i);

        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        vector<int> res;
        while (i < j)
        {
            if (nums[i] + nums[j] == target)
            {
                if (nums[i] == nums[j])
                {
                    res.push_back(mp[nums[i]][0]);
                    res.push_back(mp[nums[i]][1]);
                }
                else
                {
                    res.push_back(mp[nums[i]][0]);
                    res.push_back(mp[nums[j]][0]);
                }
                break;
            }
            else if (nums[i] + nums[j] < target)
                i++;
            else
                j--;
        }
        return res;
    }
};

class Solution
{
public:

    //using hashtable
    //time:O(n)
    //space:O(n)
    
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.find(target - nums[i]) != mp.end())
            {
                res.push_back(mp[target - nums[i]]);
                res.push_back(i);
            }
            else
            {
                mp[nums[i]] = i;
            }
        }
        return res;
    }
};