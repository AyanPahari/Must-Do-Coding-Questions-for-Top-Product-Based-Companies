class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        //extended boyer moore's voting algorithm
        //time:O(n)
        //space:O(1)

        vector<int> res;
        int n = nums.size();
        int count1 = 0, count2 = 0;
        int num1 = -1, num2 = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == num1)
                count1++;
            else if (nums[i] == num2)
                count2++;
            else if (count1 == 0)
            {
                num1 = nums[i];
                count1++;
            }
            else if (count2 == 0)
            {
                num2 = nums[i];
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        int c_num1 = 0, c_num2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == num1)
                c_num1++;
            else if (nums[i] == num2)
                c_num2++;
        }
        if (c_num1 > n / 3)
            res.push_back(num1);
        if (c_num2 > n / 3)
            res.push_back(num2);

        return res;
    }
};