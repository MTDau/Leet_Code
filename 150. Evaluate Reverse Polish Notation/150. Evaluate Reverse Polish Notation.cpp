#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        std::stack<int> nums;
        for (auto &c : tokens)
        {
            if (c == "+")
            {
                auto a = nums.top();
                nums.pop();
                auto b = nums.top();
                nums.pop();
                nums.push(b + a);
                continue;
            }
            if (c == "-")
            {
                auto a = nums.top();
                nums.pop();
                auto b = nums.top();
                nums.pop();
                nums.push(b - a);
                continue;
            }
            if (c == "*")
            {
                auto a = nums.top();
                nums.pop();
                auto b = nums.top();
                nums.pop();
                nums.push(b * a);
                continue;
            }
            if (c == "/")
            {
                auto a = nums.top();
                nums.pop();
                auto b = nums.top();
                nums.pop();
                nums.push(b / a);
                continue;
            }
            int temp{}, sign{1};
            for (auto &n : c)
            {
                if (n == '-')
                {
                    sign = -1;
                    continue;
                }
                temp = temp * 10 + n - '0';
            }
            nums.push(temp * sign);
        }
        int ans = nums.top();
        return ans;
    }
};
