//Quick thinking but wrong answer did not delete the smallest in lexicon order.
#include <string>
#include <stack>
#include <algorithm>

class Solution
{
public:
    std::string clearStars(std::string s)
    {
        std::stack<char> a;
        for (auto &c : s)
            a.push(c);
        std::string ans;
        while (!a.empty())
        {
            if (a.top() != '*')
            {
                ans.push_back(a.top());
                a.pop();
            }
            else
            {
                a.pop();
                a.pop();
            }
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
