//Update from unique path
#include <string>
#include <vector>

class Solution
{
public:
    int minPathSum(std::vector<std::vector<int>> &grid)
    {
        int r = grid.size(), c = grid[0].size();
        // Calculate the sum of following the edge:
        for (int i{1}; i < c; i++)
            grid[0][i] += grid[0][i - 1];
        for (int i{1}; i < r; i++)
            grid[i][0] += grid[i - 1][0];
        // Fill of all the grid with the minimum sum for each square:
        for (int row{1}; row < r; row++)
        {
            for (int col{1}; col < c; col++)
            {
                grid[row][col] += std::min(grid[row - 1][col], grid[row][col - 1]);
            }
        }
        return grid[r - 1][c - 1];
    }
};
