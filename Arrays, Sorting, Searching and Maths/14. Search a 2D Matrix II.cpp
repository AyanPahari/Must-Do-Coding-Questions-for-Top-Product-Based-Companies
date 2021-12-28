class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        //optimal approach
        //time:O(n+m)
        //space:O(1)

        int row = matrix.size();
        int col = matrix[0].size();
        int smallest = matrix[0][0];
        int largest = matrix[row - 1][col - 1];

        if (target < smallest || target > largest)
            return false;

        int i = 0;
        int j = col - 1;

        while (i < row && j >= 0)
        {
            if (matrix[i][j] == target)
                return true;
            if (matrix[i][j] > target)
                j--;
            else
                i++;
        }
        return false;
    }
};