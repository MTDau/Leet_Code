True answer

#include <vector>
#include <algorithm>

class Solution
{
public:
    void nextPermutation(std::vector<int> &nums)
    {
        int i = nums.size() - 1;
        while (i > 0 && nums[i - 1] >= nums[i])
        {
            i--;
        }
        if (i == 0)
        { // the case of every member is descending
            std::reverse(nums.begin(), nums.end());
            return;
        }
        int j = nums.size() - 1;
        while (j >= i && nums[j] <= nums[i - 1])
        {
            j--;
        }
        std::swap(nums[i - 1], nums[j]);
        std::reverse(nums.begin() + i, nums.end());
    }
};


//Not complete solution only work for small case
#include <vector>
#include <algorithm>

class Solution
{
public:
    void nextPermutation(std::vector<int> &nums)
    {
        bool found{false};
        for (int i = nums.size() - 1; i > 0; i--)
        {
            if (nums[i] > nums[i - 1])
            {
                bool tail{false};
                if (i + 2 < nums.size())
                {
                    tail = true;
                    int min = nums[i - 1];
                    int index{i - 1};
                    for (int j = i + 2; j < nums.size(); j--)
                    {
                        if (nums[j] < min && nums[j] != nums[i - 1])
                        {
                            min = nums[j];
                            index = j;
                        }
                        nums[index] = nums[i - 1];
                        nums[i - 1] = min;
                    }
                }
                int temp = nums[i];
                if (i + 1 == nums.size())
                {
                    nums[i] = nums[i - 1];
                    nums[i - 1] = temp;
                    found = true;
                    break;
                }
                else if (nums[i] > nums[i + 1])
                {
                    if (nums[i - 1] > nums[i + 1])
                    {
                        nums[i] = nums[i + 1],
                        nums[i + 1] = nums[i - 1],
                        nums[i - 1] = temp;
                        found = true;
                        if (tail)
                        {
                            std::sort(nums.begin() + i, nums.end());
                        }
                        break;
                    }
                    else if (nums[i - 1] < nums[i + 1])
                    {
                        nums[i] = nums[i - 1],
                        nums[i - 1] = nums[i + 1],
                        nums[i + 1] = temp;
                        found = true;
                        if (tail)
                        {
                            std::sort(nums.begin() + i, nums.end());
                        }
                        break;
                    }
                    else
                    {
                        nums[i] = nums[i - 1];
                        nums[i - 1] = temp;
                        found = true;
                        if (tail)
                        {
                            std::sort(nums.begin() + i, nums.end());
                        }
                        break;
                    }
                }
            }
        }
        if (!found)
        {
            std::sort(nums.begin(), nums.end());
        }
    }
};
