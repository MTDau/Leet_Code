//Wrong answer since dce is count as a sequence too.
#include <vector>
#include <algorithm>
#include <string>

class Solution
{
public:
    bool isMatch(std::string s, std::string p)
    {
        int ptr1 = 0, ptr2 = 0;

        for (; ptr1 < s.size() && ptr2 < p.size(); ptr1++)
        {
            if (s[ptr1] == p[ptr2])
            {
                ptr2++;
                continue;
            }
            else if (p[ptr2] == '*')
            {
                if (ptr1 + 1 < s.size() && s[ptr1] != s[ptr1 + 1])
                    ptr2++;
                continue;
            }
            else if (p[ptr2] == '?')
            {
                ptr2++;
                continue;
            }
            else
            {
                return false;
            }
        }
        if (ptr1 == s.size() && ptr2 == p.size() - 1)
            return true;
        return false;
    }
};
