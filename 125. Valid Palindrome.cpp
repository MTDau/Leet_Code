//My solution
#include <cctype>
#include <string>
#include <vector>

class Solution
{
public:
    bool isPalindrome(std::string s)
    {
        if (s.empty())
            return true;
        int left{}, right = s.size() - 1, size = s.size();
        while (left < right)
        {
            while (!check(s[left]) && left < right)
            {
                left++;
            }
            while (!check(s[right]) && left < right)
            {
                right--;
            }
            if (left == right)
                break;
            if (tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    bool check(char &c)
    {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }
};

//Best solution
