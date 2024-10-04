class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length{0};
        int left_index{0};
        unordered_map<char, int> map;

        for (int right_index{0}; right_index < s.length(); right_index++){
            char c = s[right_index];
            map[c] += 1;
            while(map[c] > 1){
                char left_char = s[left_index];
                map[left_char] -= 1;
                left_index++;
            }
            max_length = max(max_length, right_index - left_index + 1);
        }
        return max_length;
    }
};
