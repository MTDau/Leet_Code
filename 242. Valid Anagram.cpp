#include <string>
#include <map>
class Solution
{
public:
    bool isAnagram(std::string s, std::string t)
    {
        std::map<char,int> s_mp, t_mp;
        for (char c : s)
            s_mp[c]++;
        for (char c : t)
            t_mp[c]++;
        if (s_mp == t_mp)
            return true;
        return false;
    }
};
