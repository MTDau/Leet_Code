//Recursive call with backtrack
#include <vector>
using std::vector;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {

        vector<vector<int>> result{};
        vector<int> semi{};
        solve(candidates, target,result,semi,0,0);
        return result;
    }
    void solve(vector<int> &candidates, int target,vector<vector<int>>& result,vector<int>& semi, int index, int total){
        if (total == target){//Last case
            result.push_back(semi);
            return;
        }
        if (total > target || !(index < candidates.size())){//Cannot find the combination in candidates
            return;
        }
        semi.push_back(candidates[index]);
        solve(candidates, target, result, semi,index,total + candidates[index]);
        semi.pop_back();//Backtrack when no result for that type of combination.
        solve(candidates, target, result, semi,index+1,total);
    }
};
//Not complete logic redo require.
#include <vector>
#include <algorithm>
using std::vector;
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());

        vector<vector<int>> result{};
        for (int i{}; i < candidates.size(); i++)
        {
            if (candidates[0] > target)
            {
                break;
            }
            if (candidates[i] == target)
            {
                result.push_back({candidates[i]});
                break;
            }
            int mul = target / candidates[i];
            int fill = target % candidates[i];
            if (fill == 0)
            {
                std::vector<int> semi(mul, candidates[i]);
                result.push_back(semi);
            }
            else
            {
                for (int j{mul}; j > 0; j--) //Check for multiple copy of a candidate
                {
                    auto it = std::find(candidates.begin(), candidates.end(), fill);
                    if (it != candidates.end())
                    {
                        std::vector<int> semi(j, candidates[i]);
                        semi.push_back(fill);
                        std::sort(semi.begin(), semi.end());
                        result.push_back(semi);
                        fill += candidates[i];
                        continue;
                    }
                    fill += candidates[i];
                }
            }
        }
        std::sort(result.begin(), result.end());
        auto it = std::unique(result.begin(), result.end());
        result.erase(it,result.end());
        return result;
    }
};
