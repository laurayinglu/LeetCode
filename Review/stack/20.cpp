// https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        if (s.length() <= 1)
            return false;
        stack<char> st;
        // push left and pop right
        for (int i = 0; i < s.length(); i++) {
            if (st.empty() || s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);    
            else{
                if (s[i] == ')') {
                    if(st.top() != '(')
                        return false;
                }
                else if (s[i] == ']') {
                    if(st.top() != '[')
                        return false;
                }
                else if (s[i] == '}') {
                    if(st.top() != '{')
                        return false;
                }
                st.pop();
            }
        }
        // if (!st.empty())
        //     return false;
        
        return st.empty();
    }
};