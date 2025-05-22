#include <vector>
#include <algorithm>
#include <string>

class Solution
{
public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> ans{};
        sol(nums, ans,0);
        return ans;
    }
    void sol(std::vector<int> &nums, std::vector<std::vector<int>> &ans, int idx)
    {
        //Base case that all element in nums already touched.
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
