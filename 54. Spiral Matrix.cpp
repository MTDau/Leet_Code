#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix)
    {
        std::vector<int> ans;
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        while (top <= bottom && left <= right)
        {
            // Get the top row
            for (int i = left; i <= right; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++; // Move top down
            // Right collum
            for (int i = top; i <= bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--; // move right left
            // Bottom row need to check for not overlap with top row
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--; // move bottom up
            }
            // Left collum need to check for not onverlap with right collum
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++; // move left right
            }
        }
        return ans;
    }
};
