#include <vector>

class Solution
{
public:
    std::vector<int> dailyTemperatures(std::vector<int> &temperatures)
    {
        int size{temperatures.size()};
        std::vector<int> ans(size, 0);

        for (int i{size - 2}; i > -1; i--)
        {
            int j = i + 1;
            while (j < size && temperatures[j] <= temperatures[i])
            {
                if (ans[j] == 0) // There is not a day after this that have higher temp
                {
                    j = size;//Make j out of bound.
                    break;
                }
                j += ans[j]; // Jump to the day with higher temperature
            }
            if (j < size)
                ans[i] = j - i;
        }
        return ans;
    }
};

//Using stack
#include <vector>
#include <stack>
class Solution
{
public:
    std::vector<int> dailyTemperatures(std::vector<int> &temperatures)
    {
        int size = temperatures.size();
        std::vector<int> ans(size, 0);
        std::stack<std::vector<int>> stack;//{temperature, idx}
        for (int i{}; i < size; i++)
        {
            int temp = temperatures[i];
            while (!stack.empty() && temp > stack.top()[0])
            {
                auto pair = stack.top();
                stack.pop();
                ans[pair[1]] = i - pair[1];
            }
            stack.push({temp,i});
        }
        return ans;
    }
};
