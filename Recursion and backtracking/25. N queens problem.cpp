class Solution
{
public:
    bool isValid(int row, int col, vector<string> board, int n)
    {
        int temp_row = row;
        int temp_col = col;

        while (row >= 0 && col >= 0)
        { //left upward diagonal
            if (board[row--][col--] == 'Q')
                return false;
        }

        row = temp_row;
        col = temp_col;
        while (col >= 0)
        { //left diagonal
            if (board[row][col--] == 'Q')
                return false;
        }

        row = temp_row;
        col = temp_col;
        while (row < n && col >= 0)
        { //left downward diagonal
            if (board[row++][col--] == 'Q')
                return false;
        }

        return true;
    }

    void solve(int col, vector<string> &board, vector<vector<string>> &res, int n)
    {
        if (col == n)
        {
            res.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (isValid(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(col + 1, board, res, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
            board[i] = s;
        solve(0, board, res, n);

        return res;
    }
};