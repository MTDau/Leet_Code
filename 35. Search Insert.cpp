#include <vector>

class Solution
{
public:
    int searchInsert(std::vector<int> &nums, int target)
    {
        int size = nums.size();
        int l{}, r{size - 1};
        int index{};
        if (nums.empty() || nums[0] > target)
            return index;
        if (nums[size - 1] < target)
            return size;
        while (l < r)
        {
            index = l + (r - l) / 2;
            if (nums[index] == target)
                return index;
            if (nums[index] < target)
            {
                l = index + 1;
            }
            else
            {
                r = index - 1;
            }
        }
        if (nums[r] < target)
            return r + 1;
        return r;
    }
};
