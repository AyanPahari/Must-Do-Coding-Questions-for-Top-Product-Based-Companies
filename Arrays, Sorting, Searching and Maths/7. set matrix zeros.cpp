class Solution
{
public:
    //time:O((M*N)(M+N))
    //space:O(M*N)
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<vector<int>> copy;
        copy = matrix;
        int row, col;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    for (int k = 0; k < matrix[0].size(); k++)
                    {
                        //for making rows 0
                        copy[i][k] = 0;
                    }
                    for (int k = 0; k < matrix.size(); k++)
                    {
                        //for making columns 0
                        copy[k][j] = 0;
                    }
                }
            }
        }
        matrix = copy;
    }
};

class Solution
{
public:
    //time:O(M*N)
    //space:O(M+N)
    void setZeroes(vector<vector<int>> &matrix)
    {

        vector<int> row(matrix.size(), -1);
        vector<int> col(matrix[0].size(), -1);

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }
        for (int i = 0; i < row.size(); i++)
        {
            if (row[i] == 0)
            {
                for (int j = 0; j < matrix[0].size(); j++)
                    matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < col.size(); i++)
        {
            if (col[i] == 0)
            {
                for (int j = 0; j < matrix.size(); j++)
                    matrix[j][i] = 0;
            }
        }
    }
};