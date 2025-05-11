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

//Binary Search much better

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int first = -1, last = -1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
            {
                first = mid;
                r = mid - 1;
            }
            else if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        l = 0;
        r = nums.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
            {
                last = mid;
                l = mid + 1;
            }
            else if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return {first, last};
    }
};
