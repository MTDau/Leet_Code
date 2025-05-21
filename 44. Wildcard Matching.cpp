//Dynamic programing with truth table
class Solution {
public:
    bool isMatch(string s, string p) {
        int s_len = s.length(), p_len = p.length();
        int s_idx = 0, p_idx = 0;
        int star_idx = -1, s_tmp_idx = -1;

        while (s_idx < s_len) {
            if (p_idx < p_len && (p[p_idx] == '?' || p[p_idx] == s[s_idx])) {
                ++s_idx;
                ++p_idx;
            } else if (p_idx < p_len && p[p_idx] == '*') {
                star_idx = p_idx;
                s_tmp_idx = s_idx;
                p_idx++;
            } else if (star_idx == -1) {
                return false;
            } else {
                p_idx = star_idx + 1;
                s_idx = s_tmp_idx + 1;
                s_tmp_idx = s_idx;
            }
        }

        for (int i = p_idx; i < p_len; ++i) {
            if (p[i] != '*')
                return false;
        }

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
