class Solution
{
public:
    //using sorting
    //time:O(nlogn)
    //space:O(1)
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i + n / 2 < n; i++)
        {
            if (nums[i] == nums[i + n / 2])
                return nums[i];
        }
        return -1;
    }
};

class Solution
{
public:
    //using hashing
    //time:O(n)
    //space:O(n)
    int majorityElement(vector<int> &nums)
    {

        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
            mp[nums[i]]++;

        for (auto it : mp)
        {
            if (it.second > n / 2)
                return it.first;
        }
        return -1;
    }
};

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        //using Moore's voting algorithm
        //time:O(n)
        //space:O(1)
        int count = 0, ele = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
                ele = nums[i];
            if (ele == nums[i])
                count++;
            else
                count--;
        }
        return ele;
    }
};