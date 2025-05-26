//Note complete because of run time error
#include <vector>
#include <algorithm>
#include <string>

class Solution
{
public:
    std::string getPermutation(int n, int k)
    {
        std::vector<int> nums;
        for (int i{1}; i <= n; i++)
            nums.push_back(i);
        int count{0};
        std::string ans;
        std::vector<std::vector<int>> table;
        solve(k, 0, count, nums, table);
        std::sort(table.begin(), table.end());
        for (int i = 0; i < n; i++)
            ans.push_back(table[k-1][i] + '0');
        return ans;
    }

    void solve(const int &k, int idx, int &count, std::vector<int> &nums, std::vector<std::vector<int>> &table)
    {
        // if (count > k)
        //     return;
        if (idx == nums.size())
        {
            count++;
            table.push_back(nums);
            return;
        }
        for (int i{idx}; i < nums.size(); i++)
        {
            std::swap(nums[idx], nums[i]);
            solve(k, idx + 1, count, nums, table);
            std::swap(nums[idx], nums[i]); // back track;
        }
    }
};
