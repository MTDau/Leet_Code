#include <vector>
#include <algorithm>
#include <string>

class Solution
{
public:
    int jump(std::vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0 || n == 1)
            return 0;
        int jump = 1, step = nums[0];
        for (int i = 0; i + step + 1 < n; jump++)
        {
            i = max_reach(nums, i, step);
            step = nums[i];
        }
        return jump;
    }
    int max_reach(std::vector<int> &nums, int i, int step)
    {
        int max{}, next{i};
        for (int j = i + 1; j <= i + step && j < nums.size(); j++)
        {
            if (nums[j] + j > max)
            {
                max = nums[j] + j;
                next = j;
            }
        }
        return next;
    }
};
