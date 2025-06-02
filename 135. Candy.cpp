#include <vector>
#include <algorithm>

class Solution
{
public:
    int candy(std::vector<int> &ratings)
    {
        int size = ratings.size();
        std::vector<int> dp(size, 1); // Everyone have at least 1 candy
        for (int i = 1; i < size; i++)
            if (ratings[i] > ratings[i - 1])
                dp[i] = dp[i - 1] + 1;
        int ans{};
        for (int i = size - 1; i > 0; i--)
        {
            if (ratings[i - 1] > ratings[i])
                dp[i - 1] = std::max(dp[i - 1], dp[i] + 1);
            ans += dp[i];
        }
        ans += dp[0];
        return ans;
    }
};
