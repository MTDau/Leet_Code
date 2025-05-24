//Just brute force sort and unorder_map for answer.
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

class Solution
{
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
    {
        std::unordered_map<std::string, std::vector<std::string>> mp;
        for (auto &s : strs)
        {
            std::string temp = s;
            std::sort(temp.begin(), temp.end());
            mp[temp].push_back(s);
        }
        std::vector<std::vector<std::string>> ans;
        for (auto &p : mp)
        {
            ans.push_back(p.second);
        }
        return ans;
    }
};
