#include <vector>
#include <algorithm>
#include <string>

class Solution
{
public:
    std::string multiply(std::string num1, std::string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";
        int size1 = num1.size();
        int size2 = num2.size();
        int ans_size = size1 + size2;
        std::vector<int> temp(ans_size, 0);
        for (int i = size2 - 1; i > -1; i--)
        {
            int carry = 0;
            for (int j = size1 - 1; j > -1; j--)
            { // i + j + 1 = ans_size - 1
                int mul = temp[i + j + 1] + (num2[i] - '0') * (num1[j] - '0') + carry;
                temp[i + j + 1] = mul % 10;
                carry = mul / 10;
            }
            temp[i] += carry; // Add the remain carry.
        }
        //skip all leading 0
        int k{};
        while (temp[k] == 0)
        {
            k++;
        }
        std::string ans{""};
        while (k < ans_size)
        {
            ans.push_back(temp[k++] + '0');
        }
        return ans;
    }
};
