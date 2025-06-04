#include <map>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::map<int, int> mp;
        for (auto num : nums) {
            if (mp[num] > 0)
                return true;
            else
                mp[num]++;
        }
        return false;
    }
};

#include <unordered_set>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> set;
        for (auto num : nums) {
            if (set.count(num))
                return true;
            set.insert(num);
        }
        return false;
    }
};
