class Solution {
public:
    int myAtoi(string s) {
        bool sign_before_digit{true};
        bool stop_flag{false};
        char sign{43};
        long long result{};
        for (char c : s) {
            if (!stop_flag && sign_before_digit && (c == 45 || c == 43)) {
                sign = c;
                sign_before_digit = false;
                stop_flag = true;
            } else if (c >= 48 && c <= 57) {
                if (result > INT_MAX) {
                    if (sign == 45)
                        return INT_MIN;
                    return INT_MAX;
                }
                result = result * 10 + c - 48;
                stop_flag = true;
            } else if (c == 32 && !stop_flag) {
                continue;
            } else {
                break;
            }
        }
        if (sign == '-') {
            result = (-1) * result;
        }
        return result;
    }
};
