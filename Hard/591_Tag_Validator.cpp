//
//Runtime: 0
//Memory Usage: 6.7

class Solution {
public:
    int getStr(const string &code, int start){
        int res = start;
        while(res < code.size() && code[res] != '>'){
            if(code[res] > 'Z' || code[res] < 'A') return code.size();
            ++res;
        }
        return res;
    }
    bool isValid(string code) {
        stack<string> stk;
        int n = code.size();
        for(int i = 0; i < n; ++i){
            char c = code[i];
            if(i > 0 && stk.empty())return false;
            if(c == '<'){
                if(code[i + 1] == '/'){
                    if(stk.empty())return false;
                    int j = getStr(code, i + 2);
                    if(code[j] == '>' && j - i - 2 <= 9 && j - i - 2 >= 1){
                        if(stk.top() != code.substr(i + 2, j - i - 2))return false;
                        stk.pop();
                        i = j;
                    }else {
                        return false;
                    }
                    
                }else if(code.substr(i, 9) == "<![CDATA["){
                    int j = i + 9;
                    for(; j <= code.size() - 3; ++j){
                        if(code[j] == ']' && code[j + 1] == ']' && code[j + 2] == '>')break;
                    }
                    
                    if(j == code.size()){
                        return false;
                    }
                    i = j;
                    
                }else{
                    int j = getStr(code, i + 1);
                    if(code[j] == '>' && j - i - 1 <= 9 && j - i - 1 >= 1){
                        
                        stk.push(code.substr(i + 1, j - i - 1));
                    }else{
                        return false;
                    }
                    i = j;
                    
                }
            }
        }  
        return stk.empty();
    }
};