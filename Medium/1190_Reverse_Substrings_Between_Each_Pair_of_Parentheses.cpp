//
//Runtime 0
//Memory Usage 6.3

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> stk;
        string res;
        
        for(int i = 0, j = 0; i < s.size(); ++i) {
            if(s[i] == '(') {
                stk.push(j);
            } else if(s[i] == ')') {
                reverse(res.begin() + stk.top(), res.end());
                stk.pop();
            } else{
                ++j;
                res.push_back(s[i]);
            }
        }
        return res;
    }
};