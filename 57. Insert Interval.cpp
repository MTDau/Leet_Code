//Way better 3 loop
#include <vector>
#include <algorithm>
using std::vector;
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int left{newInterval[0]}, right{newInterval[1]};
        int size = intervals.size(), i = 0;
        std::vector<std::vector<int>> ans;
        while (i < size && left > intervals[i][1])
        {
            ans.push_back(intervals[i]);
            i++;
        }
        while (i < size && right >= intervals[i][0])
        {
            left = std::min(left, intervals[i][0]);
            right = std::max(right, intervals[i][1]);
            i++;
        }
        ans.push_back({left,right});
        while (i < size)
        {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
//Overthinking complicated code for 1 loop
#include <vector>
#include <algorithm>
using std::vector;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans{};
        if (intervals.size() == 0)
        {
            ans.push_back(newInterval);
            return ans;
        }
        std::vector<int> temp{newInterval};
        bool merge{false}, single{true}, got_push{false};
        int count{};
        for (int i{0}; i < intervals.size(); i++)
        {
            if (intervals[i][1] >= newInterval[0] && intervals[i][1] <= newInterval[1] 
                || intervals[i][0] <= newInterval[1] && intervals[i][0] >= newInterval[0] 
                || intervals[i][0] <= newInterval[0] && intervals[i][1] >= newInterval[1])
            {
                temp = {std::min({intervals[i][0], newInterval[0], temp[0]}), std::max({intervals[i][1], newInterval[1], temp[1]})};
                merge = false;
                single = false;
                got_push = false;
            }
            if (intervals[i][0] > newInterval[1] )
            {
                merge = true;
                single = false;
            }
            if (merge && count == 0)
            {
                ans.push_back(temp);
                merge = false;
                got_push = true;
                single = true;
                count++;
            }
            if (single || count == 1)
            {
                ans.push_back(intervals[i]);
            }
        }
        if (!got_push)
            ans.push_back(temp);
        return ans;
    }
};
