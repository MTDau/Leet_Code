//Key and value array.
class Solution {
public:
    string intToRoman(int num) {
        std::string result{};
        int num_set[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        std::string key[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                             "XL", "X",  "IX", "V",  "IV", "I"};
        int pos = 0;
        while (num > 0) {
            while (num < num_set[pos])
                pos++;
            num -= num_set[pos];
            result += key[pos];
        }
        return result;
    }
};

//Brute force
class Solution {
public:
    string intToRoman(int num) {
        std::string result{};
        while (num >= 1000) {
            result += "M";
            num -= 1000;
        }
        if (num >= 900) {
            result += "CM";
            num -= 900;
        }
        if (num >= 500) {
            result += "D";
            num -= 500;
        }
        if (num >= 400) {
            result += "CD";
            num -= 400;
        }
        while (num >= 100) {
            result += "C";
            num -= 100;
        }
        if (num >= 90) {
            result += "XC";
            num -= 90;
        }
        if (num >= 50) {
            result += "L";
            num -= 50;
        }
        if (num >= 40) {
            result += "XL";
            num -= 40;
        }
        while (num >= 10) {
            result += "X";
            num -= 10;
        }
        if (num == 9) {
            result += "IX";
            num -= 9;
        }
        if (num >= 5) {
            result += "V";
            num -= 5;
        }
        if (num == 4) {
            result += "IV";
            num -= 4;
        }
        while (num >= 1) {
            result += "I";
            num--;
        }
        return result;
    }
};
