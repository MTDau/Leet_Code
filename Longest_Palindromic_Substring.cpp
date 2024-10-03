bool check_palindrom(std::string& s) {
    for (int left = 0, right = s.size() - 1; left < right; left++, right--) {
        if (s[left] != s[right]) {
            return false;
        }
    }
    return true;
}
class Solution {
public:
    string longestPalindrome(string s) {
        int leftptr{}, window_range{1};
        int lim = s.size();
        std::string result = s.substr(0, 1); // In case palindrom is only 1 char
        for (; window_range <= lim; window_range++, leftptr = 0) {
            while (leftptr + window_range <= lim) {
                std::string test = s.substr(leftptr, window_range);
                if (check_palindrom(test)) {
                    result = test;
                }
                leftptr++;
            }
        }
        return result;
    }
};
