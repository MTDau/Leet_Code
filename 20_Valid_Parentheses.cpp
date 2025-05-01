#include <string>
#include <stack>
#include <iostream>

class Solution
{
public:
    bool isValid(std::string s)
    {
        int size = s.size();
        if (size % 2 != 0)
            return false;
        std::stack<char> temp;
        for (int i{}; i < size; i++)
        {

            switch (s[i])
            {
            case '[':
                temp.push(s[i]);
                break;
            case '{':
                temp.push(s[i]);
                break;
            case '(':
                temp.push(s[i]);
                break;
            case ']':
                if (temp.empty() || temp.top() != '[')
                    return false;
                else
                    temp.pop();
                break;
            case '}':
                if (temp.empty() || temp.top() != '{')
                    return false;
                else
                    temp.pop();
                break;
            case ')':
                if (temp.empty() || temp.top() != '(')
                    return false;
                else
                    temp.pop();
                break;
            default:
                break;
            }
        }
        return temp.empty();
    }
};

int main(){
    Solution a;
    bool result = a.isValid("()[]{}");
return 0;
}
