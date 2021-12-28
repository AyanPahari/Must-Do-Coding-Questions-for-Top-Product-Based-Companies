class Solution
{
public:
    char nextGreatestLetter(vector<char> &arr, char target)
    {
        char res = arr[0];
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int mid;

        while (low <= high)
        {
            mid = low + (high - low) / 2;

            if (arr[mid] == target)
            {
                low = mid + 1;
            }
            else if (arr[mid] > target)
            {
                res = arr[mid];
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return res;
    }
};

//link: https://leetcode.com/problems/find-smallest-letter-greater-than-target/