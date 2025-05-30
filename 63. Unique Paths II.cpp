//Another solution
#include <string>
#include <vector>

class Solution
{
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>> &grid)
    {
        if (grid[0][0] == 1)
            return 0;
        int r = grid.size(), c = grid[0].size();
        std::vector<int> dp(c, 0);
        dp[0] = 1;
        for (int i{}; i < r; i++)
        {
            for (int j{}; j < c; j++)
            {
                if (grid[i][j] == 1)
                    dp[j] = 0;
                else if (j > 0)
                    dp[j] += dp[j - 1];
            }
        }
        return dp[c - 1];
    }
};
//Update of the previous one not bad but can be better.
#include <string>
#include <vector>

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& grid) {
        // Set up the first row;
        std::vector<int> prev_row = grid[0];
        int r = grid.size(), c = prev_row.size();
        for (int i{}; i < c; i++) {
            if (prev_row[i] == 0)
                prev_row[i] = 1;
            else {
                while(i < c) {
                    prev_row[i] = 0;
                    i++;
                }
            }
        }
        // Update first row in grid
        grid[0] = prev_row;
        for (int i{1}; i < r; i++) {
            std::vector<int> curr_row = grid[i];
            if (curr_row[0] == 1)
                curr_row[0] = 0;
            else
                curr_row[0] += prev_row[0];
            for (int j{1}; j < c; j++) {
                if (curr_row[j] == 1)
                    curr_row[j] = 0;
                else
                    curr_row[j] = curr_row[j - 1] + prev_row[j];
            }
            grid[i] = curr_row;
            prev_row = curr_row;
        }
        return prev_row[c - 1];
    }
};
