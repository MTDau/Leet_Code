#include <cctype>
#include <string>
#include <iostream>

class Solution
{
public:
    bool isNumber(std::string s)
    {
        bool e_flag{false}, s_flag{false}, d_flag{false}, found_digit{false};
        const int size = s.size();
        for (int i{}; i < size; i++)
        {
            if (!std::isdigit(s[i]))
            {
                switch (s[i])
                {
                case '-':
                case '+':
                    if (s_flag || i == size - 1)
                        return false;
                    if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                        return false;
                    s_flag = true;
                    break;
                case 'e':
                case 'E':
                    if (e_flag || i == size - 1 || !found_digit)
                        return false;
                    e_flag = true;
                    s_flag = false;
                    break;
                case '.':
                    if (d_flag || e_flag)
                        return false;
                    d_flag = true;
                    break;
                default:
                    return false;
                }
            }
            else
                found_digit = true;
        }
        return found_digit;
    }
};
