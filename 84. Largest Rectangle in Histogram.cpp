#include <vector>
#include <stack>
#include <algorithm>

class Solution
{
public:
    int largestRectangleArea(std::vector<int> &heights)
    {
        int size = heights.size();
        std::stack<int> stack;
        int ans{};
        for (int i{}; i <= size; i++)
        {
            while (!stack.empty() && (i == size || heights[stack.top()] > heights[i]))
            {
                int h = heights[stack.top()];
                stack.pop();
                int w = stack.empty() ? i : i - stack.top();
                ans = std::max(ans, h * w);
            }
            stack.push(i);
        }
        return ans;
    }
};
