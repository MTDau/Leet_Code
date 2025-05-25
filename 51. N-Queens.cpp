#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

class Solution
{
public:
    inline std::vector<std::vector<std::string>> solveNQueens(int n)
    {
        std::vector<std::vector<std::string>> ans;
        std::string s(n, '.');
        std::vector<std::string> board(n, s);
        solve(n, 0, board, ans);
        return ans;
    }
    inline void solve(const int &n, int col, std::vector<std::string> &board, std::vector<std::vector<std::string>> &ans)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        for (int row{}; row < n; row++)
        {
            if (safePlace(n, row, col, board))
            {
                board[row][col] = 'Q';
                solve(n, col + 1, board, ans);
                board[row][col] = '.'; // Back track
            }
        }
    }

    inline bool safePlace(const int &n, const int &row, const int &col, std::vector<std::string> &board)
    { // Only need to check the previous row because the lower is now filled.
        int x{row - 1}, y{col - 1};
        while (y > -1)
            if (board[row][y--] == 'Q')
                return false;
        y = col - 1;
        while (x > -1 && y > -1)
            if (board[x--][y--] == 'Q')
                return false;
        x = row + 1;
        y = col - 1;
        while (x < n && y > -1)
            if (board[x++][y--] == 'Q')
                return false;
        return true;
    }
};

//good one
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

class Solution
{
public:
    inline std::vector<std::vector<std::string>> solveNQueens(int n)
    {
        std::vector<std::vector<std::string>> ans;
        std::string s(n, '.');
        std::vector<std::string> board(n, s);
        solve(n, 0, board, ans);
        return ans;
    }
    inline void solve(const int &n, int col, std::vector<std::string> &board, std::vector<std::vector<std::string>> &ans)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        for (int row{}; row < n; row++)
        {
            if (safePlace(n, row, col, board))
            {
                board[row][col] = 'Q';
                solve(n, col + 1, board, ans);
                board[row][col] = '.'; // Back track
            }
        }
    }

    inline bool safePlace(const int &n, const int &row, const int &col, std::vector<std::string> &board)
    { // Only need to check the previous row because the lower is now filled.
        for (int y{col}; y > -1; y--)
        {
            if (board[row][y] == 'Q')
                return false;
        }
        for (int x{row}, y{col}; x > -1 && y > -1; x--, y--)
        {
            if (board[x][y] == 'Q')
                return false;
        }
        for (int x{row}, y{col}; x < n && y > -1; x++, y--)
        {
            if (board[x][y] == 'Q')
                return false;
        }
        return true;
    }
};
