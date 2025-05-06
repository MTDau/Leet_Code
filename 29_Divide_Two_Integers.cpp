#include <cmath>
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        else if (dividend == INT_MAX && divisor == 1)
            return INT_MAX;
        else if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;
        else if (dividend == INT_MAX && divisor == -1)
            return INT_MIN + 1;
        int sign{1};
        if (dividend == divisor)
            return 1;
        if (dividend > 0 && divisor < 0 ||
            dividend < 0 && divisor > 0) // sign of result
            sign = -1;
        // Dividend can not contain all number
        unsigned int a = abs(static_cast<long long>(dividend));
        unsigned int b = abs(static_cast<long long>(divisor));
        int result{};
        while (a >= b)
        {
            int count{};
            // bit shift left to double divisor every loop
            while (a > (b << (count + 1)))
                count++;
            a -= b << count;
            result += 1 << count;
        }
        if (sign < 0)
            return -result;
        else
            return result;
    }
};
