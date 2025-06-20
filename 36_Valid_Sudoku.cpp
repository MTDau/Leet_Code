//Final update
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <unordered_map>
const int DIM{3};
class Solution
{
public:
    bool isValidSudoku(std::vector<std::vector<char>> &board)
    {
        // Check row and collum
        std::unordered_map<char, int> r_check, c_check;
        for (int i{}; i < 9; i++)
        {
            for (int j{}; j < 9; j++)
            {
                r_check[board[i][j]]++;
                if (board[i][j] != '.' && r_check[board[i][j]] > 1)
                    return false;
                c_check[board[j][i]]++;
                if (board[j][i] != '.' && c_check[board[j][i]] > 1)
                    return false;
            }
            r_check.clear();
            c_check.clear();
        }
        bool valid{true};
        for (int r_box{}; r_box < DIM; r_box++){
            for (int c_box{}; c_box < DIM; c_box++){
                valid = box_check(r_box,c_box,board);
                if(!valid)
                    return false;
            }
        }
        return true;
    }
    bool box_check(const int &r_box, const int &col_box, std::vector<std::vector<char>> &board)
    {
        std::unordered_map<char, int> check;
        for (int r{DIM * r_box}; r < DIM + 3 * r_box; r++)
        {
            for (int c{DIM * col_box}; c < DIM + 3 * col_box; c++)
            {
                char temp = board[r][c];
                check[temp]++;
                if (temp != '.' && check[temp] > 1)
                    return false;
            }
        }
        return true;
    }
};

//good one
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

//Bitmask way better

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0}, columns[9] = {0}, boxes[9] = {0};
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                
                int num = board[i][j] - '1'; // Convert '1'-'9' to 0-8
                int mask = 1 << num;         // Create bitmask for the number
                int boxIndex = (i / 3) * 3 + j / 3;
                
                // Check if the number is already set in the row, column, or box
                if (rows[i] & mask || columns[j] & mask || boxes[boxIndex] & mask) {
                    return false;
                }
                
                // Mark the number in the row, column, and box
                rows[i] |= mask;
                columns[j] |= mask;
                boxes[boxIndex] |= mask;
            }
        }
        return true;
    }
};
/*
explanation for box index:
we know i and j run from 0 ->8 and we need 9 box to do the check so we also need box 0->8 to do calculation.
box[0] will be i from 0->2 and j from 0->2
box[1] will be i from 0->2 and j from 3->5
box[2] will be i from 0->2 and j from 6->8
box[3] will be i from 3->5 and j from 0->2
box[4] will be i from 3->5 and j from 3->5
box[5] will be i from 3->5 and j from 6->8
box[6] will be i from 6->8 and j from 0->2
box[7] will be i from 6->8 and j from 3->5
box[8] will be i from 6->8 and j from 6->8

therefore boxIndex = (i / 3) * 3 + j / 3;

*/
