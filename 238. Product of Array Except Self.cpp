#include <string>
#include <vector>

class Solution
{
public:
    std::vector<int> productExceptSelf(std::vector<int> &nums)
    {
        std::vector<int> ans(nums.size(), 1);
        int temp{1};
        for (int i{}; i < nums.size(); i++)
        {
            ans[i] *= temp;
            temp *= nums[i];
        }
        temp = 1;
        for (int i = nums.size() - 1; i > -1; i--)
        {
            ans[i] *= temp;
            temp *= nums[i];
        }
        return ans;
    }
};
