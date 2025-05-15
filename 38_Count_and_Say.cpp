//Update of the first solution best 
#include <string>
using std::string;
class Solution {
public:
    string countAndSay(int n) {
        string ans = "1", s_ans;
        int count;
        for (int i{1}; i < n; i++) {
            s_ans = "";
            char curr = ans[0];
            count = 0;
            for (int j = 0; j < ans.size(); j++) {
                if (curr == ans[j])
                    count++;
                else {
                    s_ans += (count + '0');
                    s_ans += curr;
                    count = 1;
                    curr = ans[j];
                }
            }
            s_ans += (count + '0');
            s_ans += curr;
            ans = s_ans;
        }
        return ans;
    }
};
//Way better recursive call
class Solution
{
public:
    std::string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        std::string prev_result = countAndSay(n - 1);
        std::string result = "";
        int size = prev_result.size();
        for (int i{}; i < size; i++){
            char c = prev_result[i];
            int count{1};
            while (i < size - 1 && prev_result[i] == prev_result[i+1]){
                count++;
                i++;
            }
            result = result + std::to_string(count) + std::string(1,c);

        }
        return result;
    }
};
//First though no recursive call
#include <string>
std::string encode(std::string a);
class Solution
{
public:
    std::string countAndSay(int n)
    {
        std::string result{"1"};
        for (int i{1}; i < n; i++)
        {
            result = encode(result);
        }
        return result;
    }
};
std::string encode(std::string a)
{
    int size = a.size();
    int ptr1{}, ptr2{};
    std::string result{};
    for (; ptr2 < a.size(); ptr2++)
    {
        if (a[ptr2] == a[ptr1])
            continue;
        else
        {
            int duplicate = ptr2 - ptr1;
            result += (duplicate +'0');
            result += a[ptr2 - 1];
            ptr1 = ptr2;
        }
    }
    ptr2--; // return to the last char
    if (a[ptr2] == a[ptr1])
    {
        int dup = ptr2 - ptr1 + 1;
        result += (dup + '0');
        result += a[ptr1];
    }
    return result;
}

int main()
{
    Solution a;
    a.countAndSay(4);
    return 0;
}
