#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using std::vector;

bool s_check(vector<vector<char>> &board, int c_area, int r_area);
const int DIMENSION = 3;
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // Check each row.
        std::unordered_map<char, int> check;
        for (vector<char> &row : board)
        {
            for (char &temp : row)
            {
                check[temp]++;
                if (temp != '.' && check[temp] > 1)
                    return false;
            }
            // Clear the map for next row.
            check.clear();
        }
        // Check collum
        check.clear();
        for (int c{0}; c < 9; c++)
        {
            for (int r{0}; r < 9; r++)
            {
                char temp = board[r][c];
                check[temp]++;
                if (temp != '.' && check[temp] > 1)
                    return false;
            }
            check.clear();
        }

        // Check each 3x3 square
        bool valid = true;
        for (int r_area{}; r_area < 3; r_area++)
        {
            for (int c_area{}; c_area < 3; c_area++)
            {
                valid = s_check(board, r_area, c_area);
                if (!valid)
                    return false;
            }
        }
        return valid;
    }
};

bool s_check(vector<vector<char>> &board, int r_area, int c_area)
{
    std::unordered_map<char, int> c_square;
    for (int i = 3 * r_area; i < DIMENSION + 3 * r_area; i++)
    {
        for (int j = 3 * c_area; j < DIMENSION + 3 * c_area; j++)
        {
            char temp = board[i][j];
            c_square[temp]++;
            if (c_square[temp] > 1 && temp != '.')
                return false;
        }
    }
    return true;
}

// int main()
// {
//     Solution a;
//     std::vector<std::vector<char>> board{{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
//     std::cout << a.isValidSudoku(board);
//     return 0;
// }
