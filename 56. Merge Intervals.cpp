#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
    {
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> ans;
        std::vector<int> temp{intervals[0]};
        for (int i{1}; i < intervals.size(); i++)
        {
            if (temp[1] >= intervals[i][0])
            {
                temp[1] = std::max(temp[1], intervals[i][1]);
            }
            else
            {
                ans.push_back(temp);
                temp = intervals[i];
            }
        }
        // Push the last case to answer
        ans.push_back(temp);
        return ans;
    }
};
