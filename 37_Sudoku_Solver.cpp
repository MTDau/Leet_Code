#include <vector>

bool is_valid(std::vector<std::vector<char>> &board, int &row, int &collum, char &c);
bool solve(std::vector<std::vector<char>> &board);
class Solution
{
public:
    void solveSudoku(std::vector<std::vector<char>> &board)
    {
        solve(board);
    }
};

bool solve(std::vector<std::vector<char>> &board)
{
    for (int i{}; i < 9; i++)
    {
        for (int j{}; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    if (is_valid(board, i, j, c))
                    {
                        board[i][j] = c;
                        if (solve(board)) // call again with the board updated
                            return true;
                        board[i][j] = '.'; // Back track
                    }
                }
                return false; // No case can fit the board
            }
        }
    }
    return true;
}

bool is_valid(std::vector<std::vector<char>> &board, int &row, int &collum, char &c)
{
    // Check row and collum
    for (int i{}; i < 9; i++)
    {
        if (c == board[row][i] || c == board[i][collum])
            return false;
    }
    // Check box
    int first_row = row / 3 * 3;
    int first_col = collum / 3 * 3;
    for (int i = first_row; i < first_row + 3; i++)
    {
        for (int j = first_col; j < first_col + 3; j++)
        {
            if (c == board[i][j])
                return false;
        }
    }
    return true;
}
