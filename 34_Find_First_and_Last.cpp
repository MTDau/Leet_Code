#include <vector>
#include <algorithm>

using std::vector;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.empty())
            return {-1, -1};
        std::vector<int> result;
        auto it = std::find(nums.begin(), nums.end(), target);
        if (it == nums.end())
            return {-1, -1};
        int first = it - nums.begin();
        int second{first}, size = nums.size();
        for (; second < size; second++)
        {
            if (nums[second] > target)
                break;
        }
        second--;
        result = {first, second};
        return result;
    }
};
