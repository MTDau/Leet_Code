//Not totally working with runtime problem
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<vector<int>> result;
        for (int i{0}; i < nums.size() - 2; i++) {

            if (i > 0 && nums.at(i) == nums.at(i - 1) )
                continue;

            for (int j{i + 1}; j < nums.size() - 1; j++) {
                int target = 0 - nums[i] - nums[j];
                auto begin = nums.begin() + j + 1;
                auto it = find(begin, nums.end(), target);
                if (it != nums.end()) {
                    result.push_back({nums[i], nums[j], *it});
                }
            }
        }
        std::sort(result.begin(), result.end());
        auto it = unique(result.begin(), result.end());
        result.erase(it, result.end());
        return result;
    }
};
