#include <iostream>
#include <string>

class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {

        if (s.empty())
        {
            return ""; // empty string
        }
        result = s[0];      // In case of a single char is the answer
        int start{}, end{}; // Keep track of the palindrome substr
        for (int i = 0; i < s.size(); i++)
        {
            int event = expand(s, i, i);
            int odd = expand(s, i, i + 1);
            int len = std::max(event, odd);
            if (len > end - start) // New longest
            {
                start = i - (len - 1) / 2;
                end = i + len / 2;
                result = s.substr(start, len);
            }
        }
        return result;
    }

private:
    std::string result{};
    int expand(std::string &s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return right - left - 1;
    }
};

int main()
{
    Solution a;
    std::cout << a.longestPalindrome("0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000") << std::endl;
    return 0;
}

/*
Over runtime limit of leet code
bool check_palindrom(std::string& s) {
    for (int left = 0, right = s.size() - 1; left < right; left++, right--) {
        if (s[left] != s[right]) {
            return false;
        }
    }
    return true;
}
class Solution {
public:
    string longestPalindrome(string s) {
        int leftptr{}, window_range{1};
        int lim = s.size();
        std::string result = s.substr(0, 1); // In case palindrom is only 1 char
        for (; window_range <= lim; window_range++, leftptr = 0) {
            while (leftptr + window_range <= lim) {
                std::string test = s.substr(leftptr, window_range);
                if (check_palindrom(test)) {
                    result = test;
                }
                leftptr++;
            }
        }
        return result;
    }
};
*/
