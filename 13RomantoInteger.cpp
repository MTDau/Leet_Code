//Map solution inefficiency
class Solution {
public:
    int romanToInt(string s) {
        std::map<char, int> num_map = {{'I', 1},   {'V', 5},   {'X', 10},
                                       {'L', 50},  {'C', 100}, {'D', 500},
                                       {'M', 1000}};
        int result{};
        for (int i = s.size() - 1; i >= 0; i--) {

            if ( num_map[s[i + 1]] > num_map[s[i]]) {
                result -= num_map[s[i]];
                continue;
            }
            result += num_map[s[i]];
        }
        return result;
    }
};


// Array solution way better
class Solution {
public:
    int romanToInt(string s) {
        int num[16] = {0};
        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
            case 'I':
                num[i] = 1;
                break;
            case 'V':
                num[i] = 5;
                break;
            case 'X':
                num[i] = 10;
                break;
            case 'L':
                num[i] = 50;
                break;
            case 'C':
                num[i] = 100;
                break;
            case 'D':
                num[i] = 500;
                break;
            case 'M':
                num[i] = 1000;
                break;
            default:
                break;
            }
        }
        int result{};
        for (int i = 0; i < s.length(); i++) {
            // Found the smaller number that stand before the big number
            if (num[i] < num[i + 1]) {
                // Do the calculation
                result = result + (num[i + 1] - num[i]);
                i++; // skip the number already add
            } else
                result += num[i];
        }
        return result;
    }
};
