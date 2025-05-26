#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
class Solution
{
public:
    int lengthOfLastWord(std::string s)
    {
        int count{};
        bool f{false};
        for (int i = s.size() - 1; i > -1; i--)
        {
            if (isalpha(s[i]))
            {
                count++;
                f = true;
            }
            else if (s[i] == ' ' && f == true)
                break;
        }
        return count;
    }
};


#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
class Solution
{
public:
    int lengthOfLastWord(std::string s)
    {
        int i = s.size() - 1;
        while (i >= 0 && s[i] == ' ')
            i--;
        int ans{};
        while (i >= 0 && s[i] != ' ')
            ans++, i--;
        return ans;
    }
};
