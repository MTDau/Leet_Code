class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> my_map{};
        for (int i = 0; i < nums.size(); i++) {
            int second_number = target - nums[i];
            if (my_map.find(second_number) != my_map.end()) {
                return {my_map[second_number], i};
            }
            my_map[nums[i]] = i;
        }
        return {};
    }
};
