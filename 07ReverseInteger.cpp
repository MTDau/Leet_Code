class Solution {
public:
    int reverse(int x) {
        long result{};
        int temp{};
        while (x != 0) {
            temp = x % 10;
            result = result * 10 + temp;
            x /= 10;
        }
        if (result <= INT_MIN || result > INT_MAX)
            return 0;
        return result;
    }
};
