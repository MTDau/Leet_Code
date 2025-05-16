#include <algorithm>
#include <vector>

class Solution
{
public:
    int firstMissingPositive(std::vector<int> &nums)
    {

        std::sort(nums.begin(), nums.end());
        int target{1};
        for (int &n : nums)
        {
            if (n <= 0)
                continue;
            if (n == target)
                target++;
            else if (n > target)
                return target;
        }
        return target;
    }
};
