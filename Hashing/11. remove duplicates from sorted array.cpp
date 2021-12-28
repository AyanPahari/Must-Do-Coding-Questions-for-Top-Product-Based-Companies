class Solution
{
public:
    //using set
    //time:O(nlogn)
    //space:O(n)
    int removeDuplicates(vector<int> &nums)
    {
        set<int> s;
        for (auto it : nums)
            s.insert(it);
        int i = 0;
        for (auto it : s)
            nums[i++] = it;
        return s.size();
    }
};

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        //using two pointer technique
        //time:O(n)
        //space:O(1)
        if (nums.size() == 0)
            return 0;
        int i = 0, j = 0;
        while (j < nums.size())
        {
            if (nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
            else
                j++;
        }
        return i + 1;
    }
};