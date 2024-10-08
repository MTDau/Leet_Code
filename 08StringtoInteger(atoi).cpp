class Solution {
public:
    int myAtoi(string s) {
        bool have_sign{false};
        bool stop_flag{false};
        char sign{43};
        long result{};
        for (char c : s) {
            if (c >= 48 && c <= 57) {
                result = result * 10 + c - 48;
                stop_flag = true;
                if (result > INT_MAX) {
                    if (sign == 45)
                        return INT_MIN;
                    return INT_MAX;
                }
            } else if (!stop_flag && !have_sign && (c == 45 || c == 43)) {
                sign = c;
                have_sign = true;
                stop_flag = true;
            } else if (c == 32 && !stop_flag) {
                continue;
            } else {
                break;
            }
        }
        if (sign == 45) {
            result = (-1) * result;
        }
        return result;
    }
};
