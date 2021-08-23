//stack
//Runtime 4
//Memory Usgae 7.2

class Solution {
public:
    int longestValidParentheses(string s) {
        int size = s.length();
        stack<int> stk;
        int start = 0;
        int result = 0;
        for(int i = 0; i < size; ++i){
            if(s[i] == '(') stk.push(i);
            else{
                if(stk.empty()) start = i + 1;
                else{
                    stk.pop();
                    result = max(result, stk.empty() ? (i - start + 1) : i - stk.top() );
                    
                }
            }
        }
        return result;
    }
};
