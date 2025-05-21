//Update of the original code
#include <vector>
#include <algorithm>
#include <string>

class Solution
{
public:
    bool isMatch(std::string s, std::string p)
    {
        int s_ptr = 0, p_ptr = 0;
        int s_size = s.size(), p_size = p.size();
        int start_idx = -1, s_temp_idx = -1; // Start of the sequence
        while (s_ptr < s_size)
        {
            if ((s[s_ptr] == p[p_ptr] || p[p_ptr] == '?') && p_ptr < p_size)
            {
                s_ptr++;
                p_ptr++;
            }
            else if (p[p_ptr] == '*' && p_ptr < p_size)
            {
                start_idx = p_ptr;
                s_temp_idx = s_ptr;
                p_ptr++;
            }
            // check if there is matching * before
            else if (start_idx == -1)
            {
                return false;
            }
            else
            {//Continue with the sequence
                p_ptr = start_idx + 1;
                s_ptr = ++s_temp_idx;
            }
        }
        if (s_ptr != s_size) // Not complete the check
        {
            return false;
        }
        // Clear out the end of p string if * match with empty
        // if there left of unmatch then return false
        for (int i = p_ptr; i < p_size; ++i)
        {
            if (p[i] != '*')
                return false;
        }

        return true;
    }
};
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
