//stack
//Runtime 0
//Memory Usage 6.4
class Solution {
public:
    bool isValid(string s) {
        stack <char> p;
        for(char c : s){
            switch(c){
                case '{':
                case '(':
                case '[':
                    p.push(c);
                    break;
                case ')':
                    if(p.empty() || p.top() != '(') return false;
                    else p.pop();
                    break;
                case '}':
                    if(p.empty() || p.top() != '{') return false;
                    else p.pop();
                    break;
                case ']':
                    if(p.empty() || p.top() != '[') return false;
                    else p.pop();
                    break;
            }
        }
        return p.empty() ? true : false;
    }
};
