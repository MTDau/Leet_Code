/*
The approach is mathematical. The idea is to keep selecting a digit and eliminating it from further selection based on value of K.

For example:

Given, N = 4, K = 9

There are 6 numbers starting with 1: 1234, 1243, 1324, 1342, 1423, 1432
There are 6 numbers starting with 2: 2134, 2143, 2314, 2341, 2413, 2431
Similarly, there are 6 numbers starting with 3 and 6 numbers starting with 4.

This is because when we have chosen one place out of 4 places (as N=4), there are 3 places remaining to be filled and those 3 places can be filled in 6 ways or (N-1)! ways.

So, we have to keep identifying which digit to choose.

Initially, we have to choose a digit from {1,2,3,4}.

Since K = 9, meaning it belongs to second set of six numbers and hence, would begin with 2.

Now, first place is chosen as 2 and output string becomes "2".
This means we have eliminated 6 choices starting with 1 (1234, 1243, 1324, 1342, 1423, 1432).

Now, K would be updated as K = 9 - 6 = 3.

We now have to identify remaining 3 places with the digits {1,3,4} and with K = 3.

There are 2 numbers starting with 1: 134, 143
There are 2 numbers starting with 3: 314, 341
There are 2 numbers starting with 4: 413, 431

This is because when we have chosen one place out of 3 available places, there are 2 places remaining to be filled and those 2 places can be filled in 2 ways.

Since, K = 3, meaning it belongs to second set of two numbers and hence, answer would be appended with "3" and output string becomes "23".
This means we have eliminated 2 choices starting with 1 (134, 143).

Now, K would be updated as K = 3 - 2 = 1.

We now have to identify remaining 2 places with the digits {1,4} with K = 1.

There is 1 number starting with 1: 14
There is 1 number starting with 4: 41

This is because when we have chosen one place out of 2 available places, there is only 1 place remaining to be filled and that 1 place can be only be filled in 1 ways.

Since, K = 1, meaning it belongs to first set of one number and hence, answer would be appended with "14" and output string becomes "2314".

Therefore, final answer becomes "2314".
*/
//Final solution
#include <string>
#include <vector>

class Solution
{
public:
    void fact_cal(int n)
    {
        fact.push_back(1); // case 0
        if (n == 1)
            return;
        for (int i{1}; i < n; i++)
            fact.push_back(i * fact[i - 1]);
    }
    std::string getPermutation(int n, int k)
    {
        fact_cal(n);
        std::vector<int> nums;
        for (int i{1}; i <= n; i++)
            nums.push_back(i);
        int size = n - 1, permu = k - 1;
        int digit, rem;
        std::string ans{};
        while (size >= 0)
        {
            digit = permu / fact[size];
            rem = permu % fact[size];
            ans += (nums[digit] + '0');
            nums.erase(nums.begin() + digit);
            size--;
            permu = rem;
        }
        return ans;
    }

private:
    std::vector<int> fact;
};
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
