//
//Runtime 0
//Memory Usage 6
class Solution {
public:
    bool isNumber(string s) {
        bool hasSign = false, hasE = false, hasFlo = false, hasDig = false, hasEAf = true;
        for(int i = 0; i < s.size(); ++i){
            char c = s[i];
            if(c == ' ' && i < s.size() - 1 && s[i + 1] != ' ' && (hasDig | hasE | hasSign | hasFlo)) return false;
            else if(c == '+' || c == '-'){
                if(i  > 0 && s[i - 1] != 'E' && s[i - 1] != 'e' && s[i - 1] != ' ') return false;
                hasSign = true;
            }else if(isdigit(c)) {
                hasDig = true;
                hasEAf = true;
            }else if(c == '.'){
                if(hasFlo || hasE) return false;
                hasFlo = true;
            }else if(c == 'E' || c == 'e'){
                if(!hasDig || hasE) return false;
                hasE = true;
                hasEAf = false;
            }else return false;
        }
        return hasDig && hasEAf;
    }
    
};
