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





#include <algorithm>
#include <vector>

class Solution
{
public:
    int firstMissingPositive(std::vector<int> &nums)
    {//This use more time to run compare to the original answer.
        // Using lamda func to move all negative integer and 0 to end of vector
        auto it = std::remove_if(nums.begin(), nums.end(),
                                 [](int n)
                                 { return n <= 0; });
        // Erase the nums that we do not need to check.
        nums.erase(it, nums.end());
        std::sort(nums.begin(), nums.end());
        int target{1};
        for (int &n : nums)
        {
            if (n == target)
                target++;
            else if (n > target)
                return target;
        }
        return target;
    }
};
