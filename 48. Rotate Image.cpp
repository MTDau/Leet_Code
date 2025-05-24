#include <vector>
#include <algorithm>
#include <string>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        //it's n x n matrix so only need to get the row dimension data
        int d = matrix.size();
        //std::vector<std::vector<int>> temp(matrix);
        for (int i{}; i < d; i++){
            for (int j{i}; j < d; j++){
                //matrix[i][j] = temp[j][i];
                std::swap(matrix[i][j],matrix[j][i]);
            }
        }
        for (auto& row:matrix){
            std::reverse(row.begin(), row.end());
        }
    }
};
