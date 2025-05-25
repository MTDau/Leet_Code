#include <vector>
#include <algorithm>

class Solution
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        int size(nums.size()), sum{}, max{INT_MIN};
        for (int i{}; i < size; i++)
        {
            sum += nums[i];
            max = std::max(sum, max);
            if (sum < 0)
                sum = 0;
        }
        return max;
    }
};
