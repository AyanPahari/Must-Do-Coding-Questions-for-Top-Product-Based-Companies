class Solution
{
public:
    //Brute force approach
    //time:O(n^3)
    //space:O(1)
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int sum = 0;
                for (int k = i; k <= j; k++)
                {
                    sum += nums[k];
                    maxi = max(maxi, sum);
                }
            }
        }
        return maxi;
    }
};

class Solution
{
public:
    //better approach. removed the 3rd loop as it was unnecessary
    //time:O(n^2)
    //space:O(1)
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                maxi = max(maxi, sum);
            }
        }
        return maxi;
    }
};

class Solution
{
public:
    //Optimal Approach using Kadane's algorithm
    //time:O(n)
    //space:O(1)
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        int maxi = nums[0];

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            maxi = max(maxi, sum);
            if (sum < 0)
                sum = 0;
        }
        return maxi;
    }
};