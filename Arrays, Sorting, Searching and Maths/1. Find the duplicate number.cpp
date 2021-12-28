class Solution
{
public:
    //using hashing
    //time: O(n)
    //space: O(n)
    int findDuplicate(vector<int> &nums)
    {

        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
            if (mp[nums[i]] > 1)
                return nums[i];
        }
        return -1;
    }
};

class Solution
{
public:
    //using floyd slow and fast pointer approach
    //time: O(n)
    //space: O(1)
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0];
        int fast = nums[0];

        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};