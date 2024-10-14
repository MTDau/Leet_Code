class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string result{strs.at(0)};
        for (int i{1}; i < strs.size(); i++) {
            int length{};
            for (int j{0}; j < result.size() && j < strs.at(i).size(); j++) {
                if (strs.at(i).at(j) == result.at(j))
                    length = j + 1;
                else {
                    if (j == 0)
                        return ""; 
                    break;
                }
            }
            result = result.substr(0, length);
        }

        return result;
    }
};
