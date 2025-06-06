#include <string>
#include <vector>

class Solution
{
public:
    std::string encode(std::vector<std::string> &strs)
    {
        std::string ans{};
        for (std::string &str : strs)
        {
            int n = str.size();
            ans = ans + std::to_string(n) + "!" + str;
        }
        return ans;
    }

    std::vector<std::string> decode(std::string s)
    {
        std::vector<std::string> ans;
        int i{};
        while (i < s.size())
        {
            int j{i};
            while (s[j] != '!')
                j++;
            int len{};
            for (int k{i}; k < j; k++)
                len = len * 10 + (s[k] - '0');
            ans.push_back(s.substr(j + 1, len));
            i = j + 1 + len;
        }
        return ans;
    }
};
