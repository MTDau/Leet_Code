#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> generateMatrix(int n)
    {
        std::vector<std::vector<int>> ans(n, std::vector<int>(n, 0));
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        int fill{1};
        while (top <= bottom && left <= right)
        {
            // Get the top row
            for (int i = left; i <= right; i++)
            {
                ans[top][i] = fill++;
            }
            top++; // Move top down
            // Right collum
            for (int i = top; i <= bottom; i++)
            {
                ans[i][right] = fill++;
            }
            right--; // move right left
            // Bottom row need to check for not overlap with top row
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    ans[bottom][i] = fill++;
                }
                bottom--; // move bottom up
            }
            // Left collum need to check for not onverlap with right collum
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    ans[i][left] = fill++;
                }
                left++; // move left right
            }
        }
        return ans;
    }
};
