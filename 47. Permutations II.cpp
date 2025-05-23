//Better update compare to the previous one check for swapable members
#include <vector>
#include <algorithm>
#include <string>

class Solution
{
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> ans{};
        // Need sorting to check duplicated members
        std::sort(nums.begin(), nums.end());
        sol(nums, ans, 0);
        return ans;
    }
    void sol(std::vector<int> &nums, std::vector<std::vector<int>> &ans, int idx)
    {
        // base case
        if (idx == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int i{idx}; i < nums.size(); i++)
        {
            bool swapable{true};
            for (int j{idx}; j < i; j++)
            {//Check for duplicate member to skip the swap.
                if (nums[j] == nums[i])
                {
                    swapable = false;
                    break;
                }
            }
            if (!swapable)
                continue;
            std::swap(nums[idx], nums[i]);
            sol(nums, ans, idx + 1);
            std::swap(nums[idx], nums[i]); // back track;
        }
    }
};
//Lazy way to do this just update the old one
#include <vector>
#include <algorithm>
#include <string>

class Solution
{
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> ans{};
        sol(nums, ans,0);
        std::sort(ans.begin(), ans.end());
        auto it = std::unique(ans.begin(), ans.end());
        ans.erase(it, ans.end());
        return ans;
    }
    void sol(std::vector<int> &nums, std::vector<std::vector<int>> &ans, int idx)
    {
        if (idx == nums.size()){
            ans.push_back(nums);
            return;
        }
        for (int i{idx}; i < nums.size();i++){
            std::swap(nums[idx],nums[i]);
            sol(nums,ans,idx+1);
            std::swap(nums[idx],nums[i]);//back track;
        }
    }
};
