class Solution
{
    //link: https://leetcode.com/problems/arranging-coins/
public:
    int arrangeCoins(long long n)
    {
        long long low = 0;
        long long high = n;
        long long mid;
        long long curr;

        while (low <= high)
        {
            mid = low + (high - low) / 2;
            curr = mid * (mid + 1) / 2;

            if (curr == n)
            {
                return mid;
            }
            else if (curr > n)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return high;
    }
};