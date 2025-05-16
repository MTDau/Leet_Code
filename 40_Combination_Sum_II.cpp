//Final solution
#include <vector>
#include <algorithm>
using std::vector;

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> result{};
        vector<int> semi;
        std::sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, result, semi);
        return result;
    }
    void solve(vector<int> &candidates, int target, int index, vector<vector<int>> &result, vector<int> &semi)
    {
        if (target == 0)
        {
            result.push_back(semi);
            return;
        }
        if (target < 0)
        {
            return;
        }
        for (int i = index; i < candidates.size(); i++)
        {
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            semi.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i + 1, result, semi);
            semi.pop_back();
        }
    }
};

//My solution not complete need different logic
class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> result{};
        vector<int> semi;
        std::sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, 0, result, semi);
        return result;
    }
    void solve(vector<int> &candidates, int target, int index, int total, vector<vector<int>> &result, vector<int> &semi)
    {
        if (total == target)
        {
            result.push_back(semi);
            return;
        }
        else if (total > target || index >= candidates.size() - 1)
        {
            return;
        }
        while (candidates[index] == candidates[index + 1])
            index++;
        semi.push_back(candidates[index]);
        solve(candidates, target, index + 1, total + candidates[index], result, semi);
        semi.pop_back();
        solve(candidates, target, index + 1, total, result, semi);
    }
};
