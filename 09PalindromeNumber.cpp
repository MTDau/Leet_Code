class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        long result{};
        long temp{x};
        while (temp > 0) {
            result = result * 10 + temp % 10;
            temp /= 10;
        }
        return x == result;
    }
};
