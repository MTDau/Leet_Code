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

//Way easier to understand
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k{};
        int size = nums.size();

        for (int i{}; i < size; i++) {
            if (nums[i] != val) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};
