class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {

        int n = nums.size();
        int ind1 = -1;
        int ind2 = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                ind1 = i;
                break;
            }
        }
        if (ind1 == -1)
        {                                      //if arrangement is already of highest order possible
            reverse(nums.begin(), nums.end()); //then simply give the lowest order possible
            return;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] > nums[ind1])
            { //find the first element from the back which is greater than nums[ind1]
                ind2 = i;
                break;
            }
        }
        swap(nums[ind1], nums[ind2]);
        reverse(nums.begin() + ind1 + 1, nums.end());
    }
};