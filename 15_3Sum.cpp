//Best solution that I can think of
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<vector<int>> result;
        for (int i{0}; i < nums.size() - 2; i++) {//Check for duplicate of the first number
            if (i > 0 && nums.at(i) == nums.at(i - 1)) {
                continue;
            }

            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int total = nums[i] + nums[j] + nums[k];
                if (total > 0)
                    k--;
                else if (total < 0)
                    j++;
                else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while (nums[j] == nums[j - 1] && j < k)//Check for duplicate of the second number. who the hell think that 0,0,0,0,0,0... is evil genius.
                        j++;
                }
            }
        }
        return result;
    }
};

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
