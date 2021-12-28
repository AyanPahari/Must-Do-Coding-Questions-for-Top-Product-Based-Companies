class Solution
{
public:
    //using counting sort
    //time: O(2n)
    //space: O(1)
    void sortColors(vector<int> &arr)
    {
        int n = arr.size();
        int zero = 0;
        int one = 0;
        int two = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
                zero++;
            else if (arr[i] == 1)
                one++;
            else if (arr[i] == 2)
                two++;
        }
        int ind = 0;
        while (zero--)
        {
            arr[ind++] = 0;
        }
        while (one--)
        {
            arr[ind++] = 1;
        }
        while (two--)
        {
            arr[ind++] = 2;
        }
    }
};

class Solution
{
public:
    //using dutch national flag algorithm
    //time: O(n)
    //space: O(n)
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int mid = 0;

        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else if (nums[mid] == 2)
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};