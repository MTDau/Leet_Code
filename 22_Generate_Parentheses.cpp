
class Solution
{
private:
    void gen(int open, int close, std::string result, std::vector<std::string> &ans)
    {
        if (open == 0 && close == 0) // The last case
        {
            ans.push_back(result);
            return;
        }
        if (open == close) // No more open hanging
        {
            std::string temp = result;
            temp.push_back('(');
            gen(open - 1, close, temp, ans);
        }
        else if (open == 0)
        { // Can not open more
            std::string temp = result;
            temp.push_back(')');
            gen(open, close - 1, temp, ans);
        }
        else
        { // can be both open or close
            std::string temp1 = result;
            temp1.push_back('(');
            std::string temp2 = result;
            temp2.push_back(')');
            gen(open - 1, close, temp1, ans);
            gen(open, close - 1, temp2, ans);
        }
    }

public:
    std::vector<std::string> generateParenthesis(int n)
    {
        std::string result{};
        std::vector<std::string> ans;
        int open = n;
        int close = n;
        gen(open, close, result, ans);
        return ans;
    }
};
