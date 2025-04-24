class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest{INT_MAX}, sum{0}, tri_sum{0};
        int i{0}, j{0};
        int size = nums.size(), k{size};
        for (int i{0}; i < size; i++) {
            j = i + 1;
            k = size - 1;
            while (j < size && k >= 0 && j < k) {
                tri_sum = nums[i] + nums[j] + nums[k];
                if (abs(target - tri_sum) < closest) {
                    sum = tri_sum;
                    closest = abs(target - tri_sum);
                }
                if (tri_sum > target)
                    k--;
                else
                    j++;
            }
        }
        return sum;
    }
};
