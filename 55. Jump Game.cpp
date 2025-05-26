//Just update the old code
#include <vector>
#include <algorithm>
#include <string>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {

        int n = nums.size();
        if (n == 0 || n == 1)
            return true;
        int jump = 1, step = nums[0];
        for (int i = 0; i + step + 1 < n; jump++)
        {
            i = max_reach(nums, i, step);
            step = nums[i];
            if (step == 0){
                return false;
            }
        }
        return true;
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
