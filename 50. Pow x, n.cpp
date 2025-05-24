//Need to use buffer for the motherfucker that use MIN_INT
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

double buffer(double x, long long int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 1 / buffer(x, -n);
    // faster execution
    if (n % 2 == 1)
        return x * buffer(x * x, (n - 1) / 2);
    else
        return buffer(x * x, n / 2);
}
class Solution
{
public:
    double myPow(double x, int n)
    {
        return buffer(x,n);
    }
};

//First thought runtime problem
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1;
        double result{1};
        int sign{};
        if (n > 0)
            sign = 1;
        else if (n < 0)
            sign = -1;
        if (n >= 1 && sign > 0)
            result = x * myPow(x, n - 1);
        else if (abs(n) > 1 && sign < 0)
            result = 1 / (x * myPow(x, abs(n) - 1));
        return result;
    }
};
