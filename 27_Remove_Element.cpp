//Use std library
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int c{};
        for (int i{}; i < nums.size(); i++) {
            if (nums[i] != val) {
                c++;
            }
        }
        std::remove(nums.begin(), nums.end(), val);

        return c;
    }
};

