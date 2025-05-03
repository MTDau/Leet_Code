class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return 1;
        int count{1};
        for (int i{}, j{1}; j < nums.size(); j++) {
            int base = nums[i];
            if (base != nums[j]) {
                nums[i + 1] = nums[j];
                i++;
                count++;
            }
        }
        return count;
    }
};
