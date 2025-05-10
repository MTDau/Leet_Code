class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        if (nums[0] == target) {
            return 0;
        }
        if (nums[0] > target) {
            for (int i = nums.size() - 1; i > 0; i--) {
                if (nums[i] == target)
                    return i;
            }
        } else {
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] == target)
                    return i;
            }
        }
        return -1;
    }
};
