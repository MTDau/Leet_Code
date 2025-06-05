#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>

class Solution
{
public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k)
    {
        std::unordered_map<int, int> mp;
        for (auto &num : nums)
            mp[num]++;
        std::vector<std::pair<int, int>> temp(mp.begin(), mp.end());
        std::sort(temp.begin(), temp.end(),
                  [](const auto &a, const auto &b)
                  {
                      return a.second > b.second;
                  });
        std::vector<int> ans;
        for (int i{}; i < k; i++){
            ans.push_back(temp[i].first);
        }
        return ans;
    }
};
