//Right solution
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        std::stack<int> index;
        index.push(-1);
        int m_len = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                index.push(i);
            else
            {
                index.pop();
                if (index.empty())
                    index.push(i);
                else
                    m_len = std::max(m_len, i - index.top());
            }
        }
        return m_len;
    }
};

//First solution improve from old code
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int max_len = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    max_len = max(max_len, i - st.top());
                }
            }
        }

        return max_len;        
    }
};
