//this run time is O(nlog(n)) because of sort.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        std::sort(nums.begin(), nums.end());
        int temp{}, max{INT_MIN};
        for (int i{1}; i < nums.size(); i++) {
            if (nums[i - 1] + 1 == nums[i])
                temp++;
            else if (nums[i - 1] == nums[i])
                continue;
            else {
                max = std::max(temp + 1, max);
                temp = 0;
            }
        }
        max = std::max(temp + 1, max);
        return max;
    }
};

//Run time error
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> set(nums.begin(), nums.end());
        int max{0};
        for (int num : nums) {
            if (set.find(num - 1) == set.end()) { // Begin of the sequence
                int count{1};
                while (set.find(num + count) != set.end())
                    count++;
                max = std::max(max, count);
            }
        }
        return max;
    }
};
