class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int low = 0;
        int high = row * col - 1;
        int mid, c_row, c_col;

        while (low <= high)
        {
            mid = low + (high - low) / 2;
            c_row = mid / col;
            c_col = mid % col;

            if (matrix[c_row][c_col] == target)
                return true;
            else if (matrix[c_row][c_col] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }
};