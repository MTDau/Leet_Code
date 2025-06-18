//Back track solution
class Solution
{
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string temp;
        int open{}, close{};
        gen(open, close, n, temp, ans);
        return ans;
    }
    void gen(int open, int close, const int &n, string& temp, vector<string> &ans)
    {
        if (open == n && close == n)
        {
            ans.push_back(temp);
            return;
        }
        if (open < n)
        {
            temp += '(';
            gen(open + 1, close, n, temp, ans);
            temp.pop_back();
        }
        if (close < open)
        {
            temp += ')';
            gen(open, close + 1, n, temp, ans);
            temp.pop_back();
        }
    }
};


//Recursive indecisive
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
