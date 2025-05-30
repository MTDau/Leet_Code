#include <string>
#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        //std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        std::vector<int> prev_row(n, 1); // First row
        for (int r{1}; r < m; r++) {
            std::vector<int> curr_row(n, 1);
            for (int c{1}; c < n; c++) {
                curr_row[c] = curr_row[c - 1] + prev_row[c];
            }
            prev_row = curr_row;
        }
        return prev_row[n - 1];
    }

private:
    int count{};
};
