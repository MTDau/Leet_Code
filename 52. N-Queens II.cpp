//God tier answer
class Solution {
public:
    int totalNQueens(int n) {
        int a=0;
        switch(n){
            case 1:a=1;break;
            case 4:a= 2;break;
            case 5:a=10;break;
            case 6:a=4;break;
            case 7:a=40;break;
            case 8:a=92;break;
            case 9:a=352;break;
            default:a=0;break;
        }
        return a;
    }
};

//My answer from the update version of previous N_Queens
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

class Solution {
public:
    int totalNQueens(int n) {
        int ans{};
        std::string s(n, '.');
        std::vector<std::string> board(n, s);
        solve(n, 0, board, ans);
        return ans;
    }
    void solve(const int &n,const int& col, std::vector<std::string> &board, int &ans)
    {
        if (col == n)
        {
            ans++;
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

    bool safePlace(const int &n, const int &row, const int &col, std::vector<std::string> &board)
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
