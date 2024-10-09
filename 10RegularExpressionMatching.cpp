#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int size_s = s.size();
        int size_p = p.size();
        bool table[size_s + 1][size_p + 1];
        memset(table, false, sizeof(table));
        table[0][0] = true;
        for (int i{0}; i <= size_s; i++)
        {
            for (int j{1}; j <= size_p; j++)
            {
                if (p[j - 1] == '*')
                {
                    table[i][j] =
                        table[i][j - 2] ||
                        (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') &&
                         table[i - 1][j]);
                }
                else
                {
                    table[i][j] = i > 0 && table[i - 1][j - 1] &&
                                  (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return table[size_s][size_p];
    }
};
int main()
{
    Solution a;
    std::cout << std::boolalpha << a.isMatch("aaaaaaa", "a*");
    return 0;
}
