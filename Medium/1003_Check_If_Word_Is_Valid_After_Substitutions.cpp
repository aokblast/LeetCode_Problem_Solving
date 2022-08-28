//Greedy
//Runtime 16
//Memory Usage 8.4

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        
        for(const char c : s){
            switch(c){
                case 'a':
                    stk.push('a');
                    break;
                case 'b':
                    if(stk.empty() || stk.top() != 'a')
                        return false;
                    stk.top() = 'b';
                    break;
                case 'c':
                    if(stk.empty() || stk.top() != 'b')
                        return false;
                    stk.pop();
                    break;
            }
        }
        return stk.size() == 0;
    }
};