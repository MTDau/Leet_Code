//Optimize

class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();
        if (numRows == 1 || size <= numRows) {
            return s;
        };
        int next_word = numRows * 2 - 2;
        std::string result{};
        for (int row = 0; row < numRows; row++) {
            if (row == 0 || row == numRows - 1) {
                for (int i = row; i < size; i += next_word) {
                    result += s[i];
                }
            } else {
                for (int i = row; i < size; i += next_word) {
                    result += s[i];
                    int next = i + next_word - row * 2;
                    if (next < size)
                        result += s[next];
                }
            }
        }
        return result;
    }
};

/*
Easy solution

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        };
        std::vector<std::string> vec(numRows, "");
        bool reverse = false;

        for (int i{}, k{}; i < s.size(); i++) {
            if (k == 0)
                reverse = false;
            if (k == numRows - 1)
                reverse = true;
            if (!reverse) {
                vec.at(k) += s[i];
                k++;
            } else {
                vec.at(k) += s[i];
                k--;
            }
        }
        std::string result{};
        for (auto sub : vec) {
            result += sub;
        }
        return result;
    }
};
*/
